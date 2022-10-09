/* Copyright 2017 Fred Sundvik
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

#include "gtest/gtest.h"

extern "C" {
#include "quantum.h"
}

class GetTappingTermTest  : public ::testing::Test {};

keyrecord_t make_record(uint8_t row, uint8_t col) {
    return (keyrecord_t) {.event = ((keyevent_t){.key = MAKE_KEYPOS((row), (col)), .pressed = (true), .time = (timer_read())})};
}

TEST_F(GetTappingTermTest, TestTappingTermOnRingPinkieKey) {
    uint16_t left_keycode = LCTL_T(KC_A);
    uint16_t right_keycode = RCTL_T(KC_O);

    keyrecord_t left_record = make_record(1, 1);
    keyrecord_t right_record = make_record(1, 10);

    EXPECT_EQ(get_tapping_term(left_keycode, &left_record), TAPPING_TERM + 50);
    EXPECT_EQ(get_tapping_term(right_keycode, &right_record), TAPPING_TERM + 50);
}

TEST_F(GetTappingTermTest, TestTappingTermOnRingPinkieKeyOnQwerty) {
    uint16_t left_keycode = LCTL_T(KC_A);
    uint16_t right_keycode = RCTL_T(KC_SCLN);

    keyrecord_t left_record = make_record(1, 1);
    keyrecord_t right_record = make_record(1, 10);

    EXPECT_EQ(get_tapping_term(left_keycode, &left_record), TAPPING_TERM + 50);
    EXPECT_EQ(get_tapping_term(right_keycode, &right_record), TAPPING_TERM + 50);
}

TEST_F(GetTappingTermTest, TestTappingTermOnRingFingerKey) {
    uint16_t left_keycode = LSFT_T(KC_R);
    uint16_t right_keycode = RSFT_T(KC_I);

    keyrecord_t left_record = make_record(1, 1);
    keyrecord_t right_record = make_record(1, 10);

    EXPECT_EQ(get_tapping_term(left_keycode, &left_record), TAPPING_TERM + 50);
    EXPECT_EQ(get_tapping_term(right_keycode, &right_record), TAPPING_TERM + 50);
}

TEST_F(GetTappingTermTest, TestTappingTermOnRingFingerKeyOnQwerty) {
    uint16_t left_keycode = LSFT_T(KC_S);
    uint16_t right_keycode = RSFT_T(KC_L);

    keyrecord_t left_record = make_record(1, 1);
    keyrecord_t right_record = make_record(1, 10);

    EXPECT_EQ(get_tapping_term(left_keycode, &left_record), TAPPING_TERM + 50);
    EXPECT_EQ(get_tapping_term(right_keycode, &right_record), TAPPING_TERM + 50);
}

TEST_F(GetTappingTermTest, TestTappingTermOnIndexFingerKey) {
    uint16_t left_keycode = LGUI_T(KC_T);
    uint16_t right_keycode = LGUI_T(KC_N);

    keyrecord_t left_record = make_record(1, 4);
    keyrecord_t right_record = make_record(1, 6);

    EXPECT_EQ(get_tapping_term(left_keycode, &left_record), TAPPING_TERM);
    EXPECT_EQ(get_tapping_term(right_keycode, &right_record), TAPPING_TERM);
}

TEST_F(GetTappingTermTest, TestTappingTermOnIndexFingerKeyOnQwerty) {
    uint16_t left_keycode = LGUI_T(KC_F);
    uint16_t right_keycode = LGUI_T(KC_J);

    keyrecord_t left_record = make_record(1, 4);
    keyrecord_t right_record = make_record(1, 6);

    EXPECT_EQ(get_tapping_term(left_keycode, &left_record), TAPPING_TERM);
    EXPECT_EQ(get_tapping_term(right_keycode, &right_record), TAPPING_TERM);
}

TEST_F(GetTappingTermTest, TestTappingTermOnMiddleFingerKey) {
    uint16_t left_keycode = LGUI_T(KC_S);
    uint16_t right_keycode = LGUI_T(KC_E);

    keyrecord_t left_record = make_record(1, 3);
    keyrecord_t right_record = make_record(1, 7);

    EXPECT_EQ(get_tapping_term(left_keycode, &left_record), TAPPING_TERM);
    EXPECT_EQ(get_tapping_term(right_keycode, &right_record), TAPPING_TERM);
}

TEST_F(GetTappingTermTest, TestTappingTermOnMiddleFingerKeyOnQwerty) {
    uint16_t left_keycode = LGUI_T(KC_D);
    uint16_t right_keycode = LGUI_T(KC_K);

    keyrecord_t left_record = make_record(1, 4);
    keyrecord_t right_record = make_record(1, 6);

    EXPECT_EQ(get_tapping_term(left_keycode, &left_record), TAPPING_TERM);
    EXPECT_EQ(get_tapping_term(right_keycode, &right_record), TAPPING_TERM);
}

TEST_F(GetTappingTermTest, TestTappingTermOnThumbKey) {
    uint16_t left_keycode = LCTL_T(KC_SPACE);
    uint16_t right_keycode = LSFT_T(KC_ENTER);
    uint16_t alt_right_keycode = LALT_T(KC_BACKSPACE);

    keyrecord_t left_record = make_record(3, 2);
    keyrecord_t right_record = make_record(3, 3);
    keyrecord_t alt_right_record = make_record(3, 5);

    EXPECT_EQ(get_tapping_term(left_keycode, &left_record), TAPPING_TERM);
    EXPECT_EQ(get_tapping_term(right_keycode, &right_record), TAPPING_TERM);
    EXPECT_EQ(get_tapping_term(alt_right_keycode, &alt_right_record), TAPPING_TERM);
}
