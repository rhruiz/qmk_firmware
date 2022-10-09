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

#include "gtest/gtest.h"
#include "rhruiz_test_common.hpp"

extern "C" {
#include "quantum.h"
#include "rhruiz.h"
}

class GetTappingTermTapDanceTest  : public ::testing::Test {};

TEST_F(GetTappingTermTapDanceTest, TestTappingTermOnRingPinkieKey) {
    uint16_t keycode = TD(TD_RSHIFT_NUM);
    keyrecord_t record = make_record(1, 1);

    EXPECT_EQ(get_tapping_term(keycode, &record), TAPPING_TERM + 50);
}
