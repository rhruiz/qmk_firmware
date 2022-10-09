users_rhruiz_get_tapping_term_DEFS := -DHOME_ROW_MODS -DMATRIX_ROWS=4 -DMATRIX_COLS=12
users_rhruiz_get_tapping_term_INC := users/rhruiz

users_rhruiz_get_tapping_term_SRC := \
	platforms/test/timer.c \
	users/rhruiz/get_tapping_term.c \
	users/rhruiz/tests/test_get_tapping_term.cpp
