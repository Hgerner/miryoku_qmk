# Copyright 2019 Manna Harbour
# https://github.com/manna-harbour/miryoku

CAPS_WORD_ENABLE = yes # An alternative to capslock
TAP_DANCE_ENABLE = yes
# CONSOLE_ENABLE = yes
COMBO_ENABLE = yes
UNICODE_ENABLE = yes

INTROSPECTION_KEYMAP_C = manna-harbour_miryoku.c # keymaps

include users/manna-harbour_miryoku/custom_rules.mk

include users/manna-harbour_miryoku/post_rules.mk
