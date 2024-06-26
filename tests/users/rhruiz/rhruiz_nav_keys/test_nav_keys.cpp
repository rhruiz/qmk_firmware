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

class NavKeys : public TestFixture {};

TEST_F(NavKeys, TappingNextOsChangesKeys) {
    TestDriver driver;
    InSequence s;
    auto       nav_key = KeymapKey(0, 0, 0, NV_EOL);
    auto       next_nav_key = KeymapKey(0, 1, 0, KC_NOS);

    set_keymap({nav_key, next_nav_key});

    reset_runtime_state();

    /* press nav with first OS */
    EXPECT_REPORT(driver, (KC_LGUI));
    EXPECT_REPORT(driver, (KC_LGUI, KC_RIGHT));
    EXPECT_REPORT(driver, (KC_LGUI));
    EXPECT_EMPTY_REPORT(driver);
    tap_key(nav_key);
    testing::Mock::VerifyAndClearExpectations(&driver);

    /* press next OS key */
    EXPECT_NO_REPORT(driver);
    tap_key(next_nav_key);
    testing::Mock::VerifyAndClearExpectations(&driver);

    /* press nav key again */
    EXPECT_REPORT(driver, (KC_END));
    EXPECT_EMPTY_REPORT(driver);
    tap_key(nav_key);
    testing::Mock::VerifyAndClearExpectations(&driver);
}

TEST_F(NavKeys, TappingNextOsLoops) {
    TestDriver driver;
    InSequence s;
    auto       nav_key = KeymapKey(0, 0, 0, NV_EOL);
    auto       next_nav_key = KeymapKey(0, 1, 0, KC_NOS);

    set_keymap({nav_key, next_nav_key});

    reset_runtime_state();

    /* press nav with first OS */
    EXPECT_REPORT(driver, (KC_LGUI));
    EXPECT_REPORT(driver, (KC_LGUI, KC_RIGHT));
    EXPECT_REPORT(driver, (KC_LGUI));
    EXPECT_EMPTY_REPORT(driver);
    tap_key(nav_key);
    testing::Mock::VerifyAndClearExpectations(&driver);

    for (int i = 0; i < NUM_NAV_KEYS_OSES; i++) {
        EXPECT_NO_REPORT(driver);
        tap_key(next_nav_key);
    }
    testing::Mock::VerifyAndClearExpectations(&driver);

    /* expected to be first OS again */
    EXPECT_REPORT(driver, (KC_LGUI));
    EXPECT_REPORT(driver, (KC_LGUI, KC_RIGHT));
    EXPECT_REPORT(driver, (KC_LGUI));
    EXPECT_EMPTY_REPORT(driver);
    tap_key(nav_key);
    testing::Mock::VerifyAndClearExpectations(&driver);
}
