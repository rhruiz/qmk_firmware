users_rhruiz_get_tapping_term_DEFS := -DHOME_ROW_MODS -DMATRIX_ROWS=4 -DMATRIX_COLS=12
users_rhruiz_get_tapping_term_INC := users/rhruiz

users_rhruiz_get_tapping_term_SRC := \
	platforms/test/timer.c \
	users/rhruiz/get_tapping_term.c \
	users/rhruiz/tests/rhruiz_test_common.cpp \
	users/rhruiz/tests/test_get_tapping_term.cpp

users_rhruiz_get_tapping_term_no_home_row_mods_DEFS := -DMATRIX_ROWS=4 -DMATRIX_COLS=12
users_rhruiz_get_tapping_term_no_home_row_mods_INC := users/rhruiz

users_rhruiz_get_tapping_term_no_home_row_mods_SRC := \
	platforms/test/timer.c \
	users/rhruiz/get_tapping_term.c \
	users/rhruiz/tests/rhruiz_test_common.cpp \
	users/rhruiz/tests/test_get_tapping_term_no_hrm.cpp

users_rhruiz_get_tapping_term_tap_dance_DEFS := -DTAP_DANCE_ENABLE -DMATRIX_ROWS=4 -DMATRIX_COLS=12
users_rhruiz_get_tapping_term_tap_dance_INC := users/rhruiz

users_rhruiz_get_tapping_term_tap_dance_SRC := \
	platforms/test/timer.c \
	users/rhruiz/get_tapping_term.c \
	users/rhruiz/tests/rhruiz_test_common.cpp \
	users/rhruiz/tests/test_get_tapping_term_tap_dance.cpp
