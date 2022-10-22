#include "rhruiz.h"

#ifdef BLINK_LED_PIN

extern rhruiz_runtime_state runtime_state;

void blink_led(uint16_t duration_ms, uint8_t times) {
    if (times > UINT8_MAX / 2) {
        times = UINT8_MAX / 2;
    }

    runtime_state.blink_times_remaining = times * 2;
    runtime_state.blink_dur = duration_ms;
    runtime_state.blink_repeat_timer = sync_timer_read();

    blink_led_task();
}

void blink_led_task() {
    if (runtime_state.blink_times_remaining == 0) {
        return;
    }

    if (timer_expired(sync_timer_read(), runtime_state.blink_repeat_timer)) {
        writePin(BLINK_LED_PIN, runtime_state.blink_times_remaining % 2 == 1);

        if (runtime_state.blink_times_remaining > 0) {
            runtime_state.blink_times_remaining--;
            runtime_state.blink_repeat_timer = sync_timer_read() + runtime_state.blink_dur;
        }
    }
}
#endif
