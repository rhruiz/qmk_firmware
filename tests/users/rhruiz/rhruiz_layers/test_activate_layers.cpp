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

class ActivateLayers : public TestFixture {};

#define add_trns(layer, col, row) add_key(KeymapKey(layer, col, row, KC_TRNS))

TEST_F(ActivateLayers, LowerGonnaLower) {
    TestDriver driver;
    InSequence s;

    auto lower = KeymapKey(_BL, 0, 0, MO_LWR);
    auto raise = KeymapKey(_BL, 0, 1, MO_RSE);

    add_key(lower);
    add_key(raise);

    add_trns(_FN1, 0, 0);
    add_trns(_FN1, 0, 1);
    add_trns(_FN2, 0, 0);
    add_trns(_FN2, 0, 1);

    default_layer_set(0);
    reset_runtime_state();

    lower.press();
    run_one_scan_loop();

    EXPECT_NO_REPORT(driver);
    EXPECT_EQ(IS_LAYER_ON(_FN1), true);
    EXPECT_EQ(IS_LAYER_ON(_FN2), false);
    EXPECT_EQ(IS_LAYER_ON(_AUG), false);
    testing::Mock::VerifyAndClearExpectations(&driver);

    lower.release();
}

TEST_F(ActivateLayers, RaiseGonnaRaise) {
    TestDriver driver;
    InSequence s;

    auto lower = KeymapKey(0, 0, 0, MO_LWR);
    auto raise = KeymapKey(0, 0, 1, MO_RSE);

    add_key(lower);
    add_key(raise);

    add_trns(_FN1, 0, 0);
    add_trns(_FN1, 0, 1);
    add_trns(_FN2, 0, 0);
    add_trns(_FN2, 0, 1);

    default_layer_set(0);
    reset_runtime_state();

    raise.press();
    run_one_scan_loop();

    EXPECT_NO_REPORT(driver);
    EXPECT_EQ(IS_LAYER_ON(_FN1), false);
    EXPECT_EQ(IS_LAYER_ON(_FN2), true);
    EXPECT_EQ(IS_LAYER_ON(_AUG), false);
    testing::Mock::VerifyAndClearExpectations(&driver);

    raise.release();
}

TEST_F(ActivateLayers, RaiseAndLowerActivateAugmented) {
    TestDriver driver;
    InSequence s;

    auto lower = KeymapKey(_BL, 0, 0, MO_LWR);
    auto raise = KeymapKey(_BL, 0, 1, MO_RSE);

    add_key(lower);
    add_key(raise);

    add_trns(_FN1, 0, 0);
    add_trns(_FN1, 0, 1);
    add_trns(_FN2, 0, 0);
    add_trns(_FN2, 0, 1);
    add_trns(_AUG, 0, 0);
    add_trns(_AUG, 0, 1);

    default_layer_set(0);
    reset_runtime_state();

    lower.press();
    raise.press();
    run_one_scan_loop();

    EXPECT_NO_REPORT(driver);
    EXPECT_EQ(IS_LAYER_ON(_AUG), true);
    testing::Mock::VerifyAndClearExpectations(&driver);

    lower.release();
    raise.release();
}

TEST_F(ActivateLayers, GameLowerActivates) {
    TestDriver driver;
    InSequence s;

    auto lower = KeymapKey(_BL, 0, 0, OSL_GLWR);
    auto raise = KeymapKey(_BL, 0, 1, MO_RSE);

    add_key(lower);
    add_key(raise);

    add_trns(_GAMEFN1, 0, 0);
    add_trns(_GAMEFN1, 0, 1);
    add_trns(_FN2, 0, 0);
    add_trns(_FN2, 0, 1);
    add_trns(_AUG, 0, 0);
    add_trns(_AUG, 0, 1);

    default_layer_set(0);
    reset_runtime_state();

    tap_key(lower);

    EXPECT_NO_REPORT(driver);
    EXPECT_EQ(IS_LAYER_ON(_GAMEFN1), true);
    testing::Mock::VerifyAndClearExpectations(&driver);

    lower.release();
}

TEST_F(ActivateLayers, GameLowerAndRaiseActivateAugmentedWhenGameIsOn) {
    TestDriver driver;
    InSequence s;

    auto lower = KeymapKey(_BL, 0, 0, OSL_GLWR);
    auto raise = KeymapKey(_BL, 0, 1, MO_RSE);
    auto tg_game = KeymapKey(_BL, 0, 2, TG_GAME);

    add_key(lower);
    add_key(raise);
    add_key(tg_game);

    add_trns(_GAME, 0, 0);
    add_trns(_GAME, 0, 1);
    add_trns(_GAME, 0, 2);
    add_trns(_GAMEFN1, 0, 0);
    add_trns(_GAMEFN1, 0, 1);
    add_trns(_GAMEFN1, 0, 2);
    add_trns(_FN2, 0, 0);
    add_trns(_FN2, 0, 1);
    add_trns(_FN2, 0, 2);
    add_trns(_AUG, 0, 0);
    add_trns(_AUG, 0, 1);
    add_trns(_AUG, 0, 2);

    default_layer_set(0);
    reset_runtime_state();

    EXPECT_NO_REPORT(driver);
    tap_key(tg_game);
    EXPECT_EQ(IS_LAYER_ON(_GAME), true);
    testing::Mock::VerifyAndClearExpectations(&driver);

    EXPECT_NO_REPORT(driver);
    raise.press();
    run_one_scan_loop();
    EXPECT_NO_REPORT(driver);

    tap_key(lower);
    testing::Mock::VerifyAndClearExpectations(&driver);

    EXPECT_EQ(IS_LAYER_ON(_AUG), true);

    EXPECT_NO_REPORT(driver);
    lower.release();
    raise.release();
    run_one_scan_loop();
    testing::Mock::VerifyAndClearExpectations(&driver);
}
