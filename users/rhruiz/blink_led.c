#include "rhruiz.h"

#ifdef BLINK_LED_PIN

uint16_t blink_repeat_timer;
uint8_t  blink_times_remaining;
uint16_t blink_dur;

void blink_led(uint16_t duration_ms, uint8_t times) {
    if (times > UINT8_MAX / 2) {
        times = UINT8_MAX / 2;
    }

    blink_times_remaining = times * 2;
    blink_dur = duration_ms;
    blink_repeat_timer = sync_timer_read();

    blink_led_task();
#ifdef SPLIT_KEYBOARD

    if (is_keyboard_master()) {
        const uint8_t data[] = { (uint8_t)duration_ms, times };
        transaction_rpc_send(USER_SYNC_BLINK_LED, sizeof(data), &data);
    }
#endif
}

void blink_led_task() {
    if (blink_times_remaining == 0) {
        return;
    }

    if (timer_expired(sync_timer_read(), blink_repeat_timer)) {
        writePin(BLINK_LED_PIN, blink_times_remaining % 2 == 1);

        if (blink_times_remaining > 0) {
            blink_times_remaining--;
            blink_repeat_timer = sync_timer_read() + blink_dur;
        }
    }
}

void blink_led_handler(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data) {
    const uint8_t *blink_data = (const uint8_t*)in_data;

    blink_led(blink_data[0], blink_data[1]);
}
#endif
