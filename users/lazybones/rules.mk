MOUSEKEY_ENABLE = yes #마우스키
EXTRAKEY_ENABLE = no #기타 기능키(미디어키 등)
AUTO_SHIFT_ENABLE = yes #오토쉬프트 기능
TAP_DANCE_ENABLE = yes #탭댄스 기능
CAPS_WORD_ENABLE = no #캡스워드 기능
KEY_OVERRIDE_ENABLE = yes #키 오버라이드 기능
COMBO_ENABLE = yes #콤보
DYNAMIC_MACRO_ENABLE = yes #다이나믹 매크로
DIGITIZER_ENABLE = yes

CONSOLE_ENABLE = no #디버그용(단순 용량 줄이기)

INTROSPECTION_KEYMAP_C = lazybones.c # keymaps

include users/lazybones/custom_rules.mk

include users/lazybones/post_rules.mk