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
#include "quantum.h"
#include "users/rhruiz/rhruiz.h"
}

using testing::_;
using testing::InSequence;

class NextDefaultLayout : public TestFixture {};

TEST_F(NextDefaultLayout, TappingChangesBaseLayout) {
    TestDriver driver;
    InSequence s;
    auto qwerty = KeymapKey(_QWER, 0, 0, KC_F);
    auto colemak = KeymapKey(_CODH, 0, 0, KC_T);
    auto next_layout = KeymapKey(0, 0, 1, KC_LAYO);

    set_keymap({qwerty, colemak, next_layout});
    default_layer_set(0);
    reset_runtime_state();

    EXPECT_EQ(IS_LAYER_ON_STATE(default_layer_state, _QWER), true);

    EXPECT_REPORT(driver, (KC_F));
    EXPECT_EMPTY_REPORT(driver);
    tap_key(qwerty);
    testing::Mock::VerifyAndClearExpectations(&driver);

    /* tap for next default layout */
    EXPECT_NO_REPORT(driver);
    tap_key(next_layout);
    testing::Mock::VerifyAndClearExpectations(&driver);

    EXPECT_REPORT(driver, (KC_T));
    EXPECT_EMPTY_REPORT(driver);
    tap_key(colemak);
    testing::Mock::VerifyAndClearExpectations(&driver);

    EXPECT_EQ(IS_LAYER_ON_STATE(default_layer_state, _CODH), true);
}

TEST_F(NextDefaultLayout, LayersLoop) {
    TestDriver driver;
    InSequence s;
    auto qwerty = KeymapKey(_QWER, 0, 0, KC_F);
    auto colemak = KeymapKey(_CODH, 0, 0, KC_T);
    auto next_layout = KeymapKey(_QWER, 0, 1, KC_LAYO);
    auto transparent = KeymapKey(_CODH, 0, 1, KC_TRNS);

    set_keymap({qwerty, colemak, next_layout, transparent});
    default_layer_set(0);
    reset_runtime_state();

    EXPECT_EQ(IS_LAYER_ON_STATE(default_layer_state, _QWER), true);

    EXPECT_NO_REPORT(driver);
    tap_key(next_layout);
    testing::Mock::VerifyAndClearExpectations(&driver);

    EXPECT_EQ(IS_LAYER_ON_STATE(default_layer_state, _CODH), true);

    EXPECT_NO_REPORT(driver);
    tap_key(next_layout);
    testing::Mock::VerifyAndClearExpectations(&driver);

    EXPECT_EQ(IS_LAYER_ON_STATE(default_layer_state, _QWER), true);
}

TEST_F(NextDefaultLayout, SetDefaultLayerByIndex) {
    TestDriver driver;
    InSequence s;
    auto qwerty = KeymapKey(_QWER, 0, 0, KC_F);
    auto colemak = KeymapKey(_CODH, 0, 0, KC_T);
    auto layout0 = KeymapKey(_QWER, 0, 1, KC_LAY0);
    auto layout1 = KeymapKey(_QWER, 0, 2, KC_LAY1);
    auto transparent0 = KeymapKey(_CODH, 0, 1, KC_TRNS);
    auto transparent1 = KeymapKey(_CODH, 0, 2, KC_TRNS);

    set_keymap({qwerty, colemak, layout0, layout1, transparent0, transparent1});
    default_layer_set(0);
    reset_runtime_state();

    EXPECT_EQ(IS_LAYER_ON_STATE(default_layer_state, _QWER), true);

    // tap layout0
    EXPECT_NO_REPORT(driver);
    tap_key(layout0);
    testing::Mock::VerifyAndClearExpectations(&driver);

    EXPECT_EQ(IS_LAYER_ON_STATE(default_layer_state, _QWER), true);

    // tap layout1
    EXPECT_NO_REPORT(driver);
    tap_key(layout1);
    testing::Mock::VerifyAndClearExpectations(&driver);

    EXPECT_EQ(IS_LAYER_ON_STATE(default_layer_state, _CODH), true);

    // tap layout1
    EXPECT_NO_REPORT(driver);
    tap_key(layout1);
    testing::Mock::VerifyAndClearExpectations(&driver);

    EXPECT_EQ(IS_LAYER_ON_STATE(default_layer_state, _CODH), true);

    // tap layout0
    EXPECT_NO_REPORT(driver);
    tap_key(layout0);
    testing::Mock::VerifyAndClearExpectations(&driver);

    EXPECT_EQ(IS_LAYER_ON_STATE(default_layer_state, _QWER), true);
}
