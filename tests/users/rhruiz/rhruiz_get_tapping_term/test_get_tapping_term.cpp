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
#include "users/rhruiz/rhruiz.h"

extern "C" {
#include "quantum.h"
}

using testing::_;
using testing::InSequence;

class GetTappingTermTest : public TestFixture {};

TEST_F(GetTappingTermTest, TestTappingTermOnPinkieKey) {
    TestDriver driver;
    InSequence s;
    auto left_keycode = KeymapKey(0, 0, 1, LCTL_T(KC_A));
    auto right_keycode = KeymapKey(0, 9, 1, RCTL_T(KC_O));

    set_keymap({left_keycode, right_keycode});

    EXPECT_REPORT(driver, (KC_A));
    EXPECT_EMPTY_REPORT(driver);
    tap_key(left_keycode, TAPPING_TERM + 10);

    EXPECT_REPORT(driver, (KC_O));
    EXPECT_EMPTY_REPORT(driver);
    tap_key(right_keycode, TAPPING_TERM + 10);
    testing::Mock::VerifyAndClearExpectations(&driver);
}

TEST_F(GetTappingTermTest, TestHoldingTermOnPinkieKey) {
    TestDriver driver;
    InSequence s;
    auto left_keycode = KeymapKey(0, 0, 1, LCTL_T(KC_A));
    auto right_keycode = KeymapKey(0, 9, 1, RCTL_T(KC_O));

    set_keymap({left_keycode, right_keycode});

    EXPECT_REPORT(driver, (KC_LCTL));
    EXPECT_EMPTY_REPORT(driver);
    tap_key(left_keycode, TAPPING_TERM + 50);

    EXPECT_REPORT(driver, (KC_RCTL));
    EXPECT_EMPTY_REPORT(driver);
    tap_key(right_keycode, TAPPING_TERM + 50);
    testing::Mock::VerifyAndClearExpectations(&driver);
}

TEST_F(GetTappingTermTest, TestTappingTermOnRingFingerKey) {
    TestDriver driver;
    InSequence s;
    auto left_keycode = KeymapKey(0, 1, 1, LSFT_T(KC_R));
    auto right_keycode = KeymapKey(0, 8, 1, RSFT_T(KC_I));

    set_keymap({left_keycode, right_keycode});

    EXPECT_REPORT(driver, (KC_R));
    EXPECT_EMPTY_REPORT(driver);
    tap_key(left_keycode, TAPPING_TERM + 10);
    testing::Mock::VerifyAndClearExpectations(&driver);

    EXPECT_REPORT(driver, (KC_I));
    EXPECT_EMPTY_REPORT(driver);
    tap_key(right_keycode, TAPPING_TERM + 10);
    testing::Mock::VerifyAndClearExpectations(&driver);
}

TEST_F(GetTappingTermTest, TestHoldingTermOnRingFingerKey) {
    TestDriver driver;
    InSequence s;
    auto left_keycode = KeymapKey(0, 1, 1, LSFT_T(KC_R));
    auto right_keycode = KeymapKey(0, 8, 1, RSFT_T(KC_I));

    set_keymap({left_keycode, right_keycode});

    EXPECT_REPORT(driver, (KC_LSFT));
    EXPECT_EMPTY_REPORT(driver);
    tap_key(left_keycode, TAPPING_TERM + 50);
    testing::Mock::VerifyAndClearExpectations(&driver);

    EXPECT_REPORT(driver, (KC_RSFT));
    EXPECT_EMPTY_REPORT(driver);
    tap_key(right_keycode, TAPPING_TERM + 50);
    testing::Mock::VerifyAndClearExpectations(&driver);
}

TEST_F(GetTappingTermTest, TestTappingTermOnIndexFingerKey) {
    TestDriver driver;
    InSequence s;
    auto left_keycode = KeymapKey(0, 3, 1, LGUI_T(KC_T));
    auto right_keycode = KeymapKey(0, 6, 1, RGUI_T(KC_N));

    set_keymap({left_keycode, right_keycode});

    EXPECT_REPORT(driver, (KC_T));
    EXPECT_EMPTY_REPORT(driver);
    tap_key(left_keycode, TAPPING_TERM - 5);
    testing::Mock::VerifyAndClearExpectations(&driver);

    EXPECT_REPORT(driver, (KC_N));
    EXPECT_EMPTY_REPORT(driver);
    tap_key(right_keycode, TAPPING_TERM - 5);
    testing::Mock::VerifyAndClearExpectations(&driver);
}

TEST_F(GetTappingTermTest, TestHoldingTermOnIndexFingerKey) {
    TestDriver driver;
    InSequence s;
    auto left_keycode = KeymapKey(0, 3, 1, LGUI_T(KC_T));
    auto right_keycode = KeymapKey(0, 6, 1, RGUI_T(KC_N));

    set_keymap({left_keycode, right_keycode});

    EXPECT_REPORT(driver, (KC_LGUI));
    EXPECT_EMPTY_REPORT(driver);
    tap_key(left_keycode, TAPPING_TERM);
    testing::Mock::VerifyAndClearExpectations(&driver);

    EXPECT_REPORT(driver, (KC_RGUI));
    EXPECT_EMPTY_REPORT(driver);
    tap_key(right_keycode, TAPPING_TERM);
    testing::Mock::VerifyAndClearExpectations(&driver);
}

TEST_F(GetTappingTermTest, TestTappingTermOnMiddleFingerKey) {
    TestDriver driver;
    InSequence s;
    auto left_keycode = KeymapKey(0, 2, 1, LALT_T(KC_S));
    auto right_keycode = KeymapKey(0, 7, 1, RALT_T(KC_E));

    set_keymap({left_keycode, right_keycode});

    EXPECT_REPORT(driver, (KC_S));
    EXPECT_EMPTY_REPORT(driver);
    tap_key(left_keycode, TAPPING_TERM - 5);
    testing::Mock::VerifyAndClearExpectations(&driver);

    EXPECT_REPORT(driver, (KC_E));
    EXPECT_EMPTY_REPORT(driver);
    tap_key(right_keycode, TAPPING_TERM - 5);
    testing::Mock::VerifyAndClearExpectations(&driver);
}

TEST_F(GetTappingTermTest, TestHoldingTermOnMiddleFingerKey) {
    TestDriver driver;
    InSequence s;
    auto left_keycode = KeymapKey(0, 2, 1, LALT_T(KC_S));
    auto right_keycode = KeymapKey(0, 7, 1, RALT_T(KC_E));

    set_keymap({left_keycode, right_keycode});

    EXPECT_REPORT(driver, (KC_LALT));
    EXPECT_EMPTY_REPORT(driver);
    tap_key(left_keycode, TAPPING_TERM);
    testing::Mock::VerifyAndClearExpectations(&driver);

    EXPECT_REPORT(driver, (KC_RALT));
    EXPECT_EMPTY_REPORT(driver);
    tap_key(right_keycode, TAPPING_TERM);
    testing::Mock::VerifyAndClearExpectations(&driver);
}

TEST_F(GetTappingTermTest, TestTappingTermOnThumbKey) {
    TestDriver driver;
    InSequence s;
    auto left_keycode = KeymapKey(0, 2, 3, LCTL_T(KC_SPACE));
    auto right_keycode = KeymapKey(0, 3, 3, LSFT_T(KC_ENTER));
    auto alt_right_keycode = KeymapKey(0, 5, 3, RALT_T(KC_BACKSPACE));

    EXPECT_EQ(MATRIX_ROWS, 4);

    set_keymap({left_keycode, right_keycode, alt_right_keycode});

    EXPECT_REPORT(driver, (KC_SPACE));
    EXPECT_EMPTY_REPORT(driver);
    tap_key(left_keycode, TAPPING_TERM - 5);
    testing::Mock::VerifyAndClearExpectations(&driver);

    EXPECT_REPORT(driver, (KC_ENTER));
    EXPECT_EMPTY_REPORT(driver);
    tap_key(right_keycode, TAPPING_TERM - 5);
    testing::Mock::VerifyAndClearExpectations(&driver);

    EXPECT_REPORT(driver, (KC_BACKSPACE));
    EXPECT_EMPTY_REPORT(driver);
    tap_key(alt_right_keycode, TAPPING_TERM - 5);
    testing::Mock::VerifyAndClearExpectations(&driver);
}

TEST_F(GetTappingTermTest, TestHoldingTermOnThumbKey) {
    TestDriver driver;
    InSequence s;
    auto left_keycode = KeymapKey(0, 2, 3, LCTL_T(KC_SPACE));
    auto right_keycode = KeymapKey(0, 3, 3, LSFT_T(KC_ENTER));
    auto alt_right_keycode = KeymapKey(0, 5, 3, RALT_T(KC_BACKSPACE));

    EXPECT_EQ(MATRIX_ROWS, 4);

    set_keymap({left_keycode, right_keycode, alt_right_keycode});

    EXPECT_REPORT(driver, (KC_LCTL));
    EXPECT_EMPTY_REPORT(driver);
    tap_key(left_keycode, TAPPING_TERM);
    testing::Mock::VerifyAndClearExpectations(&driver);

    EXPECT_REPORT(driver, (KC_LSFT));
    EXPECT_EMPTY_REPORT(driver);
    tap_key(right_keycode, TAPPING_TERM);
    testing::Mock::VerifyAndClearExpectations(&driver);

    EXPECT_REPORT(driver, (KC_RALT));
    EXPECT_EMPTY_REPORT(driver);
    tap_key(alt_right_keycode, TAPPING_TERM);
    testing::Mock::VerifyAndClearExpectations(&driver);
}
