#pragma once

#include "../../config.h"

// Enable key for bootmagic lite.
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0

#ifdef MANUFACTURER
#    undef MANUFACTURER
#endif

#ifdef PRODUCT
#    undef PRODUCT
#endif

#ifdef DESCRIPTION
#    undef DESCRIPTION
#endif

#define MANUFACTURER rhruiz
#define PRODUCT rhruiz one
#define DESCRIPTION rhruiz one keyboard
