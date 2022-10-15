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

class CopyPasteKeys : public TestFixture {};

TEST_F(CopyPasteKeys, HoldingForLongerThanTappingTerm) {
    TestDriver driver;
    InSequence s;
    auto       cccp_key = KeymapKey(0, 0, 0, KC_CCCP);
    auto       next_nav_key = KeymapKey(0, 1, 0, KC_NOS);

    set_keymap({cccp_key, next_nav_key});

    reset_runtime_state();

    /* press copy/paste key */
    EXPECT_REPORT(driver, (KC_LGUI));
    EXPECT_REPORT(driver, (KC_LGUI, KC_C));
    EXPECT_REPORT(driver, (KC_LGUI));
    EXPECT_EMPTY_REPORT(driver);
    tap_key(cccp_key, TAPPING_TERM + 10);
    testing::Mock::VerifyAndClearExpectations(&driver);
}

TEST_F(CopyPasteKeys, HoldingForLongerThanTappingTermOnWindows) {
    TestDriver driver;
    InSequence s;
    auto       cccp_key = KeymapKey(0, 0, 0, KC_CCCP);
    auto       next_nav_key = KeymapKey(0, 1, 0, KC_NOS);

    set_keymap({cccp_key, next_nav_key});

    reset_runtime_state();

    /* press next OS key */
    EXPECT_NO_REPORT(driver);
    tap_key(next_nav_key);
    testing::Mock::VerifyAndClearExpectations(&driver);

    /* press copy/paste key */
    EXPECT_REPORT(driver, (KC_LCTL));
    EXPECT_REPORT(driver, (KC_LCTL, KC_C));
    EXPECT_REPORT(driver, (KC_LCTL));
    EXPECT_EMPTY_REPORT(driver);
    tap_key(cccp_key, TAPPING_TERM + 10);
    testing::Mock::VerifyAndClearExpectations(&driver);
}

TEST_F(CopyPasteKeys, HoldingForShorterThanTappingTerm) {
    TestDriver driver;
    InSequence s;
    auto       cccp_key = KeymapKey(0, 0, 0, KC_CCCP);
    auto       next_nav_key = KeymapKey(0, 1, 0, KC_NOS);

    set_keymap({cccp_key, next_nav_key});

    reset_runtime_state();

    /* press copy/paste key */
    EXPECT_REPORT(driver, (KC_LGUI));
    EXPECT_REPORT(driver, (KC_LGUI, KC_V));
    EXPECT_REPORT(driver, (KC_LGUI));
    EXPECT_EMPTY_REPORT(driver);
    tap_key(cccp_key, TAPPING_TERM - 10);
    testing::Mock::VerifyAndClearExpectations(&driver);
}

TEST_F(CopyPasteKeys, HoldingForShorterThanTappingTermOnWindows) {
    TestDriver driver;
    InSequence s;
    auto       cccp_key = KeymapKey(0, 0, 0, KC_CCCP);
    auto       next_nav_key = KeymapKey(0, 1, 0, KC_NOS);

    set_keymap({cccp_key, next_nav_key});

    reset_runtime_state();

    /* press next OS key */
    EXPECT_NO_REPORT(driver);
    tap_key(next_nav_key);
    testing::Mock::VerifyAndClearExpectations(&driver);

    /* press copy/paste key */
    EXPECT_REPORT(driver, (KC_LCTL));
    EXPECT_REPORT(driver, (KC_LCTL, KC_V));
    EXPECT_REPORT(driver, (KC_LCTL));
    EXPECT_EMPTY_REPORT(driver);
    tap_key(cccp_key, TAPPING_TERM - 10);
    testing::Mock::VerifyAndClearExpectations(&driver);
}
