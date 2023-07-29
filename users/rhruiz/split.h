#pragma once
#include "rhruiz.h"

void sync_master_state_task(rhruiz_runtime_state *state);
void sync_runtime_state_handler(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data);
