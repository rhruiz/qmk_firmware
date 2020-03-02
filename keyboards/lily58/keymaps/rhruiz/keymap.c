#include QMK_KEYBOARD_H
#include "rhruiz.h"
#include "rhruiz_kc_keys.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BL] = LAYOUT_kc(
// .-----+-----+-----+-----+-----+-----.                .-----+-----+-----+-----+-----+-----.
     GRV ,  1  ,  2  ,  3  ,  4  ,  5  ,                   6  ,  7  ,  8  ,  9  ,  0  , ESC ,
// |-----+-----+-----+-----+-----+-----|                |-----+-----+-----+-----+-----+-----|
     TAB ,  Q  ,  W  ,  E  ,  R  ,  T  ,                   Y  ,  U  ,  I  ,  O  ,  P  , MINS,
// |-----+-----+-----+-----+-----+-----|                |-----+-----+-----+-----+-----+-----|
     CESC,  A  ,  S  ,  D  ,  F  ,  G  ,                   H  ,  J  ,  K  ,  L  , SCLN, QUOT,
// |-----+-----+-----+-----+-----+-----|-----|    |-----|-----+-----+-----+-----+-----+-----|
     LSFT,  Z  ,  X  ,  C  ,  V  ,  B  , _TAP,      EPIP,  N  ,  M  , COMM, DOT , SLSH, RSFT,
// `-----+-----+-----+-----+-----+----/-----/      \-----\----+-----+-----+-----+-----+-----'
                    LALT, LGUI, _FN1 , SPC ,          ENT , _FN2 , BSPC, RGUI
//                `-----+-----+----'/-----/          \-----\'----+-----+-----'
  ),

  [_VIM_EMACS] = LAYOUT_kc(
// .-----+-----+-----+-----+-----+-----.                .-----+-----+-----+-----+-----+-----.
         ,     ,     ,     ,     ,     ,                      ,     ,     ,     ,     ,     ,
// |-----+-----+-----+-----+-----+-----|                |-----+-----+-----+-----+-----+-----|
         ,     ,     ,     ,     ,     ,                      ,     ,     ,     ,     ,     ,
// |-----+-----+-----+-----+-----+-----|                |-----+-----+-----+-----+-----+-----|
         ,     ,     ,     ,     ,     ,                      ,     ,     ,     ,     ,     ,
// |-----+-----+-----+-----+-----+-----|-----|    |-----|-----+-----+-----+-----+-----+-----|
         ,     ,     ,     ,     ,     ,     ,          ,     ,     ,     ,     ,     ,     ,
// `-----+-----+-----+-----+-----+----/-----/      \-----\----+-----+-----+-----+-----+-----'
                        ,     ,      ,     ,              ,      ,     ,
//                `-----+-----+----'/-----/          \-----\'----+-----+-----'
  ),

  [_MOUSE] = LAYOUT_kc(
// .-----+-----+-----+-----+-----+-----.                .-----+-----+-----+-----+-----+-----.
         ,     ,     ,     ,     ,     ,                      ,     ,     ,     ,     ,     ,
// |-----+-----+-----+-----+-----+-----|                |-----+-----+-----+-----+-----+-----|
         ,     ,     ,     ,     ,     ,                      ,     ,     ,     ,     ,     ,
// |-----+-----+-----+-----+-----+-----|                |-----+-----+-----+-----+-----+-----|
         ,     ,     ,     ,     ,     ,                      ,     ,     ,     ,     ,     ,
// |-----+-----+-----+-----+-----+-----|-----|    |-----|-----+-----+-----+-----+-----+-----|
         ,     ,     ,     ,     ,     ,     ,          ,     ,     ,     ,     ,     ,     ,
// `-----+-----+-----+-----+-----+----/-----/      \-----\----+-----+-----+-----+-----+-----'
                        ,     ,      ,     ,              ,      ,     ,
//                `-----+-----+----'/-----/          \-----\'----+-----+-----'
  ),

  [_KEY_OVERRIDE] = LAYOUT_kc( \
// .-----+-----+-----+-----+-----+-----.                .-----+-----+-----+-----+-----+-----.
         ,     ,     ,     ,     ,     ,                      ,     ,     ,     ,     ,     ,
// |-----+-----+-----+-----+-----+-----|                |-----+-----+-----+-----+-----+-----|
         ,     ,     ,     ,     ,     ,                      ,     ,     ,     ,     , DEL ,
// |-----+-----+-----+-----+-----+-----|                |-----+-----+-----+-----+-----+-----|
         ,     ,     ,     ,     ,     ,                      ,     ,     ,     , COLN, DQUO,
// |-----+-----+-----+-----+-----+-----|-----|    |-----|-----+-----+-----+-----+-----+-----|
         ,     ,     ,     ,     ,     ,     ,          ,     ,     ,     ,     , QUES,     ,
// `-----+-----+-----+-----+-----+----/-----/      \-----\----+-----+-----+-----+-----+-----'
                        ,     ,      ,     ,              ,      ,     ,
//                `-----+-----+----'/-----/          \-----\'----+-----+-----'
  ),
  [_FN1] = LAYOUT_kc(
// .-----+-----+-----+-----+-----+-----.                .-----+-----+-----+-----+-----+-----.
      F1 ,  F2 ,  F3 ,  F4 ,  F5 ,  F6 ,                   F7 ,  F8 ,  F9 , F10 , F11 , F12 ,
// |-----+-----+-----+-----+-----+-----|                |-----+-----+-----+-----+-----+-----|
     GRV ,  1  ,  2  ,  3  ,  4  ,  5  ,                   6  ,  7  ,  8  ,  9  ,  0  ,     ,
// |-----+-----+-----+-----+-----+-----|                |-----+-----+-----+-----+-----+-----|
         , BSLS, LBRC, RBRC, MINS, PLUS,                      , LPRN, RPRN,     ,     ,     ,
// |-----+-----+-----+-----+-----+-----|-----|    |-----|-----+-----+-----+-----+-----+-----|
         ,     ,     ,     ,     ,     , _TAN,          ,     ,     ,     ,     ,     ,     ,
// `-----+-----+-----+-----+-----+----/-----/      \-----\----+-----+-----+-----+-----+-----'
                               ,     ,     ,              ,     ,      ,     ,
//                `-----+-----+----'/-----/          \-----\'----+-----+-----'
  ),

 [_FN2] = LAYOUT_kc(
// .-----+-----+-----+-----+-----+-----.                .-----+-----+-----+-----+-----+-----.
     TILD, EXLM,  AT , HASH, DLR , PERC,                  CIRC, AMPR, ASTR, LPRN, RPRN,     ,
// |-----+-----+-----+-----+-----+-----|                |-----+-----+-----+-----+-----+-----|
     TILD, EXLM,  AT , HASH, DLR,  PERC,                  CIRC, AMPR, ASTR, LPRN, RPRN,     ,
// |-----+-----+-----+-----+-----+-----|                |-----+-----+-----+-----+-----+-----|
         , PIPE, LCBR, RCBR, UNDS, EQL ,                  LEFT, DOWN,  UP , RGHT, COLN, DQUO,
// |-----+-----+-----+-----+-----+-----|-----|    |-----|-----+-----+-----+-----+-----+-----|
         ,     ,     ,     ,     ,     , _BCK,          ,     ,     ,  LT ,  GT ,     ,     ,
// `-----+-----+-----+-----+-----+----/-----/      \-----\----+-----+-----+-----+-----+-----'
                               ,     ,     ,              ,     ,      ,     ,
//                `-----+-----+----'/-----/          \-----\'----+-----+-----'
 ),

  [_CFG] = LAYOUT_kc(
// .-----+-----+-----+-----+-----+-----.                .-----+-----+-----+-----+-----+-----.
     ESC , SLCK, PAUS, MISS, RVAD, RVAI,                      ,     ,     ,     ,     , _RST,
// |-----+-----+-----+-----+-----+-----|                |-----+-----+-----+-----+-----+-----|
     MAKE, RTOG, RMOD, RHUI, RSAI, RVAI,                      ,     ,     ,     ,     ,     ,
// |-----+-----+-----+-----+-----+-----|                |-----+-----+-----+-----+-----+-----|
         , _VUP, _VDN, MUTE, EJCT,     ,                  HOME, PGDN, PGUP, END ,     ,     ,
// |-----+-----+-----+-----+-----+-----|-----|    |-----|-----+-----+-----+-----+-----+-----|
         ,     ,     ,     ,     ,     ,     ,      _TGN,     ,     ,     ,     ,     ,     ,
// `-----+-----+-----+-----+-----+----/-----/      \-----\----+-----+-----+-----+-----+-----'
                        ,     ,      ,     ,              ,      ,     ,
//                `-----+-----+----'/-----/          \-----\'----+-----+-----'
  ),

  [_NUM] = LAYOUT_kc(
// .-----+-----+-----+-----+-----+-----.                .-----+-----+-----+-----+-----+-----.
         ,  1  ,  2  ,  3  ,  4  ,  5  ,                   6  ,  7  ,  8  ,  9  ,  0  ,     ,
// |-----+-----+-----+-----+-----+-----|                |-----+-----+-----+-----+-----+-----|
         , BTN1, MS_U, BTN2, WH_D,     ,                      ,  4  ,  5  ,  6  , PLUS,     ,
// |-----+-----+-----+-----+-----+-----|                |-----+-----+-----+-----+-----+-----|
         , MS_L, MS_D, MS_R, WH_U,     ,                  ASTR,  1  ,  2  ,  3  , MINS,     ,
// |-----+-----+-----+-----+-----+-----|-----|    |-----|-----+-----+-----+-----+-----+-----|
         ,     ,     ,     ,     ,     ,     ,      _TGN, EQL ,  0  ,     ,     ,     ,     ,
// `-----+-----+-----+-----+-----+----/-----/      \-----\----+-----+-----+-----+-----+-----'
                        ,     ,      ,     ,              ,      ,     ,
//                `-----+-----+----'/-----/          \-----\'----+-----+-----'
  ),

/* template
// .-----+-----+-----+-----+-----+-----.                .-----+-----+-----+-----+-----+-----.
         ,     ,     ,     ,     ,     ,                      ,     ,     ,     ,     ,     ,
// |-----+-----+-----+-----+-----+-----|                |-----+-----+-----+-----+-----+-----|
         ,     ,     ,     ,     ,     ,                      ,     ,     ,     ,     ,     ,
// |-----+-----+-----+-----+-----+-----|                |-----+-----+-----+-----+-----+-----|
         ,     ,     ,     ,     ,     ,                      ,     ,     ,     ,     ,     ,
// |-----+-----+-----+-----+-----+-----|-----|    |-----|-----+-----+-----+-----+-----+-----|
         ,     ,     ,     ,     ,     ,     ,          ,     ,     ,     ,     ,     ,     ,
// `-----+-----+-----+-----+-----+----/-----/      \-----\----+-----+-----+-----+-----+-----'
                        ,     ,      ,     ,              ,      ,     ,
//                `-----+-----+----'/-----/          \-----\'----+-----+-----'
*/
};

#ifdef OLED_DRIVER_ENABLE

extern volatile bool isLeftHand;

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!isLeftHand) {
      return OLED_ROTATION_180;
  }
  return rotation;
}

// When add source files to SRC in rules.mk, you can use functions.
// const char *read_logo(void);
// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

static const char lc[][3][3] = {
    [_BL] = { { 0x20, 0x20, 0 }, { 0x20, 0x20, 0 }, { 0x20, 0x20, 0 } },
    [_FN1] = { { 0x80, 0x81, 0 }, { 0xa0, 0xa1, 0 }, { 0xc0, 0xc1, 0 } },
    [_FN2] = { { 0x80, 0x81, 0 }, { 0xa0, 0xa1, 0 }, { 0xc2, 0xc3, 0 } },
    [_CFG] = { { 0x84, 0x85, 0 }, { 0xa4, 0xa5, 0 }, { 0xc4, 0xc5, 0 } },
    [_NUM] = { { 0xa0, 0xa1, 0 }, { 0x20, 0x20, 0 }, { 0xa2, 0xa3, 0 } },
};

void rhruiz_render_oled(void) {
    layer_state_t layer = biton32(layer_state);
    oled_write_ln(" ", false);

    oled_write("           ", false);
    oled_write_ln(lc[layer][0], false);

    oled_write("           ", false);
    oled_write_ln(lc[layer][1], false);

    oled_write("           ", false);
    oled_write_ln(lc[layer][2], false);
}

void rhruiz_render_logo_and_layer(void) {
    layer_state_t layer = biton32(layer_state);

    const char logo1[] = { 0x20, 0x20, 0x9d, 0x9e, 0x9f, 0x20, 0x20, 0x20, 0x88, 0x20, 0x20, 0x20, 0x20, 0x20, 0x16, 0x20, 0x20, 0x20, lc[layer][0][0], lc[layer][0][1], 0 };
    const char logo2[] = { 0x20, 0x20, 0xbd, 0xbe, 0xbf, 0x20, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xce, 0xaf, 0xb0, 0x20, lc[layer][1][0], lc[layer][1][1], 0 };
    const char logo3[] = { 0x20, 0x20, 0xdd, 0xde, 0xdf, 0x20, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0x20, lc[layer][2][0], lc[layer][2][1], 0 };

    oled_write_ln(logo1, false);
    oled_write_ln(logo2, false);
    oled_write_ln(logo3, false);
}

void oled_task_user(void) {
  if (is_keyboard_master()) {
    rhruiz_render_oled();
  } else {
    rhruiz_render_logo_and_layer();
  }
}

#endif
