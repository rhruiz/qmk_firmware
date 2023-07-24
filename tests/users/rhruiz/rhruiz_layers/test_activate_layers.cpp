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
#include "test_activate_layers.hpp"

extern "C" {
#include "quantum.h"
#include "users/rhruiz/rhruiz.h"
}

using testing::_;
using testing::InSequence;

TEST_F(ActivateLayers, LowerGonnaLower) {
    TestDriver driver;
    InSequence s;

    auto lower = KeymapKey(_QWER, 0, 0, MO_LWR);
    auto raise = KeymapKey(_QWER, 0, 1, MO_RSE);
    layer_t layers[2] = { _FN1, _FN2 };

    add_key(lower);
    add_key(raise);
    setup_trns(layers, 2, 2);

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
    layer_t layers[2] = { _FN1, _FN2 };

    add_key(lower);
    add_key(raise);
    setup_trns(layers , 2, 2);

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

    auto lower = KeymapKey(_QWER, 0, 0, MO_LWR);
    auto raise = KeymapKey(_QWER, 0, 1, MO_RSE);
    layer_t layers[3] = { _FN1, _FN2, _AUG };

    add_key(lower);
    add_key(raise);
    setup_trns(layers, 3, 2);

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

    auto lower = KeymapKey(_QWER, 0, 0, OSL_GLWR);
    auto raise = KeymapKey(_QWER, 0, 1, MO_RSE);
    layer_t layers[3] = { _GAMEFN1, _FN2, _AUG };

    add_key(lower);
    add_key(raise);
    setup_trns(layers, 3, 2);

    default_layer_set(0);
    reset_runtime_state();

    tap_key(lower);

    EXPECT_NO_REPORT(driver);
    EXPECT_EQ(IS_LAYER_ON(_GAMEFN1), true);
    testing::Mock::VerifyAndClearExpectations(&driver);
}

TEST_F(ActivateLayers, GameLowerAndRaiseActivateAugmentedWhenGameIsOn) {
    TestDriver driver;
    InSequence s;

    auto lower = KeymapKey(_QWER, 0, 0, OSL_GLWR);
    auto raise = KeymapKey(_QWER, 0, 1, MO_RSE);
    auto tg_game = KeymapKey(_QWER, 0, 2, TG_GAME);
    layer_t layers[4] = { _GAME, _GAMEFN1, _FN2, _AUG };

    add_key(lower);
    add_key(raise);
    add_key(tg_game);

    setup_trns(layers, 4, 3);

    default_layer_set(0);
    reset_runtime_state();

    EXPECT_NO_REPORT(driver);
    tap_key(tg_game);
    EXPECT_EQ(IS_LAYER_ON(_GAME), true);
    testing::Mock::VerifyAndClearExpectations(&driver);

    tap_key(lower);
    EXPECT_NO_REPORT(driver);

    EXPECT_NO_REPORT(driver);
    raise.press();
    run_one_scan_loop();
    EXPECT_NO_REPORT(driver);

    testing::Mock::VerifyAndClearExpectations(&driver);

    EXPECT_EQ(IS_LAYER_ON(_AUG), true);

    EXPECT_NO_REPORT(driver);
    raise.release();
    run_one_scan_loop();
    testing::Mock::VerifyAndClearExpectations(&driver);
}

void ActivateLayers::setup_trns(layer_t layers[], uint8_t count, uint8_t rows) {
    test_logger.trace() << "Got " << +count << " layers" << std::endl;

    for (uint8_t i = 0; i < count; i++) {
        for(uint8_t j = 0; j < rows; j++) {
            test_logger.trace() << "Setting layer " << +layers[i] << " (col, row) = (" << 0 << ", " <<  +j << ") to trns" << std::endl;
            add_key(KeymapKey(layers[i], 0, j, KC_TRNS));
        }
    }
}
