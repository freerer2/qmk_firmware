#pragma once

// 콤보 정의(이름, 작동키, 콤보키)
#define COMBO_LIST \
COMBO_X(left_thumb,		KC_ESC,		LT(U_NAV,KC_SPC),	LT(U_FUN,KC_TAB)) \
COMBO_X(mouse_thumb,	KC_BTN3,	KC_BTN1,			KC_BTN2) \
COMBO_X(right_thumb,	KC_DEL,		LT(U_SYM,KC_ENT),	LT(U_NUM,KC_BSPC)) \
COMBO_X(XC,				KC_UNDS,	KC_X,				KC_C) \
COMBO_X(SD,				KC_ALGR,	LALT_T(KC_S),		LCTL_T(KC_D)) \
COMBO_X(KL,				KC_CAPS,	LCTL_T(KC_K),		LALT_T(KC_L)) \
COMBO_X(COMMDOT,		KC_B,		KC_COMM,			KC_DOT) \
COMBO_X(ER,				KC_T,		KC_E,				KC_R) \
COMBO_X(UI,				KC_Y,		KC_U,				KC_I) \
COMBO_X(DF,				KC_G,		LCTL_T(KC_D),		LSFT_T(KC_F)) \
COMBO_X(JK,				KC_H,		LSFT_T(KC_J),		LCTL_T(KC_K)) \
COMBO_X(CV,				KC_B,		KC_C,				KC_V) \
COMBO_X(MCOMM,			KC_N,		KC_M,				KC_COMM)

//COMBO_X(SD,				S(KC_SPC),	LALT_T(KC_S),		LCTL_T(KC_D))
