extern "C" {
#include "quantum.h"
}

keyrecord_t make_record(uint8_t row, uint8_t col) {
    return (keyrecord_t) {.event = ((keyevent_t){.key = MAKE_KEYPOS((row), (col)), .pressed = (true), .time = (timer_read())})};
}
