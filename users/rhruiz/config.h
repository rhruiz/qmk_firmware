#pragma once

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define LAYER_STATE_16BIT

#ifdef SPLIT_KEYBOARD
#    define SPLIT_TRANSACTION_IDS_USER USER_SYNC_RUNTIME_STATE
#endif

