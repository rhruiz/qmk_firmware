# Copyright 2022 rhruiz
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

SRC += users/rhruiz/nav_keys.c \
	   users/rhruiz/runtime_state.c \
	   users/rhruiz/keymap_callbacks/keymap_callbacks.c \
	   users/rhruiz/rhruiz.c \
	   users/rhruiz/macros.c \
	   users/rhruiz/base_layers.c \
	   platforms/test/timer.c

DEBOUNCE_TYPE = none
