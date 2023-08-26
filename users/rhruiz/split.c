#include "rhruiz.h"

typedef struct _master_to_slave_t {
    uint8_t nav_keys_index;
#ifdef CAPS_WORD_ENABLE
    bool caps_word_enabled;
#endif
} master_to_slave_t;

void sync_master_state_task(void) {
    if (needs_runtime_state_sync()) {
        master_to_slave_t m2s = {
            nav_keys_index(),
#    ifdef CAPS_WORD_ENABLE
            caps_word_enabled()
#    endif
        };

        if (transaction_rpc_send(USER_SYNC_RUNTIME_STATE, sizeof(m2s), &m2s)) {
            set_needs_runtime_state_sync(false);
        } else {
            dprintf("sync tx failed");
        }
    }
}

void sync_runtime_state_handler(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data) {
    const master_to_slave_t *mstate = (const master_to_slave_t*)in_data;

    set_nav_keys_index(mstate->nav_keys_index);
#ifdef CAPS_WORD_ENABLE
    set_caps_word_enabled(mstate->caps_word_enabled);
#endif
}
