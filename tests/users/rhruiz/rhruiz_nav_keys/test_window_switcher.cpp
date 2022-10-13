/* Copyright 2022 rhruiz
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "keyboard_report_util.hpp"
#include "keycode.h"
#include "test_common.hpp"
#include "test_keymap_key.hpp"

extern "C" {
#include "timer.h"
#include "users/rhruiz/rhruiz.h"
}

using testing::_;
using testing::InSequence;

class WindowSwitcher : public TestFixture {};

TEST_F(WindowSwitcher, MacWindowSwitching) {
    TestDriver driver;
    InSequence s;
    auto       nav_layer = KeymapKey(0, 0, 0, MO(_FN2));
    auto       next_nav_keys = KeymapKey(0, 0, 1, KC_NOS);
    auto       window_switcher = KeymapKey(_FN2, 1, 0, KC_CTAB);

    set_keymap({window_switcher, nav_layer, next_nav_keys, KeymapKey(_FN2, 0, 0, 1, KC_TRNS)});

    reset_runtime_state();

    /* change to RAISE layer */
    nav_layer.press();
    EXPECT_NO_REPORT(driver);
    run_one_scan_loop();
    testing::Mock::VerifyAndClearExpectations(&driver);

    /* tap window switcher key - mod must get in and stay on */
    EXPECT_REPORT(driver, (KC_LGUI));
    EXPECT_REPORT(driver, (KC_LGUI, KC_TAB));
    EXPECT_REPORT(driver, (KC_LGUI));
    tap_key(window_switcher);
    testing::Mock::VerifyAndClearExpectations(&driver);

    /* tap window switcher again - mod must stay on */
    window_switcher.press();
    EXPECT_REPORT(driver, (KC_LGUI, KC_TAB));
    EXPECT_REPORT(driver, (KC_LGUI));
    tap_key(window_switcher);
    testing::Mock::VerifyAndClearExpectations(&driver);

    /* release layer key - mod must release */
    nav_layer.release();
    EXPECT_EMPTY_REPORT(driver);
    run_one_scan_loop();
    testing::Mock::VerifyAndClearExpectations(&driver);
}

TEST_F(WindowSwitcher, WinLinuxWindowSwitching) {
    TestDriver driver;
    InSequence s;
    auto       nav_layer = KeymapKey(0, 0, 0, MO(_FN2));
    auto       next_nav_keys = KeymapKey(0, 0, 1, KC_NOS);
    auto       window_switcher = KeymapKey(_FN2, 1, 0, KC_CTAB);

    set_keymap({window_switcher, nav_layer, next_nav_keys, KeymapKey(_FN2, 0, 0, 1, KC_TRNS)});

    reset_runtime_state();
    tap_key(next_nav_keys);

    /* change to RAISE layer */
    nav_layer.press();
    EXPECT_NO_REPORT(driver);
    run_one_scan_loop();
    testing::Mock::VerifyAndClearExpectations(&driver);

    /* tap window switcher key - mod must get in and stay on */
    EXPECT_REPORT(driver, (KC_LALT));
    EXPECT_REPORT(driver, (KC_LALT, KC_TAB));
    EXPECT_REPORT(driver, (KC_LALT));
    tap_key(window_switcher);
    testing::Mock::VerifyAndClearExpectations(&driver);

    /* tap window switcher again - mod must stay on */
    window_switcher.press();
    EXPECT_REPORT(driver, (KC_LALT, KC_TAB));
    EXPECT_REPORT(driver, (KC_LALT));
    tap_key(window_switcher);
    testing::Mock::VerifyAndClearExpectations(&driver);

    /* release layer key - mod must release */
    nav_layer.release();
    EXPECT_EMPTY_REPORT(driver);
    run_one_scan_loop();
    testing::Mock::VerifyAndClearExpectations(&driver);
}
