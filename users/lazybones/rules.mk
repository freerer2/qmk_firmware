MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = no
AUTO_SHIFT_ENABLE = yes
TAP_DANCE_ENABLE = yes
CAPS_WORD_ENABLE = no
KEY_OVERRIDE_ENABLE = yes
COMBO_ENABLE = yes
CONSOLE_ENABLE = no

INTROSPECTION_KEYMAP_C = lazybones.c # keymaps

include users/lazybones/custom_rules.mk

include users/lazybones/post_rules.mk