#pragma once

#include "./keymap_keycode_setting.h"

#if defined (DOUBLE_B)

	#define LAYER_BASE \
	KC_Q,				KC_W,				KC_E,				KC_R,				KC_T,				KC_Y,				KC_U,				KC_I,				KC_O,				KC_P,				\
	LGUI_T(KC_A),		LALT_T(KC_S),		LCTL_T(KC_D),		LSFT_T(KC_F),		KC_G,				KC_H,				LSFT_T(KC_J),		LCTL_T(KC_K),		LALT_T(KC_L),		LGUI_T(KC_QUOT),	\
	LT(U_MOUSE,KC_Z),	KC_X,				KC_C,				KC_V,				KC_B,				KC_B,				KC_N,				KC_M,				KC_DOT,				LT(U_MOUSE,KC_COMM),\
											LT(U_DEBUG,KC_ESC),	LT(U_NAV,KC_SPC),	LT(U_FUN,KC_TAB),	LT(U_SYM,KC_ENT),	LT(U_NUM,KC_BSPC),	KC_DEL

	#define LAYER_NUM \
	KC_LBRC,			KC_7,				KC_8,				KC_9,				KC_RBRC,			KC_NO,				DF(U_BASE),			KC_NO,				KC_NO,				TD(U_TD_BOOT),		\
	KC_SCLN,			KC_4,				KC_5,				KC_6,				KC_PLUS,			KC_NO,				KC_LSFT,			KC_LCTL,			KC_LALT,			KC_LGUI,			\
	KC_SLSH,			KC_1,				KC_2,				KC_3,				KC_BSLS,			KC_NO,				DF(U_NUM),			DF(U_NAV),			KC_ALGR,			KC_RCTL,			\
											KC_GRV,				KC_0,				KC_MINS,			KC_NO,				KC_NO,				KC_NO

	#define LAYER_SYM \
	KC_LCBR,			KC_AMPR,			KC_ASTR,			KC_LPRN,			KC_RCBR,			KC_NO,				DF(U_BASE),			KC_NO,				KC_NO,				TD(U_TD_BOOT),		\
	KC_COLN,			KC_DLR,				KC_PERC,			KC_CIRC,			KC_EQL,				KC_NO,				KC_LSFT,			KC_LCTL,			KC_LALT,			KC_LGUI,			\
	KC_QUES,			KC_EXLM,			KC_AT,				KC_HASH,			KC_PIPE,			KC_NO,				DF(U_SYM),			DF(U_FUN),			KC_ALGR,			KC_RCTL,			\
											KC_TILD,			KC_RPRN,			KC_UNDS,			KC_NO,				KC_NO,				KC_NO
#else

	#define LAYER_BASE \
	KC_Q,				KC_W,				KC_E,				KC_R,				KC_T,				KC_Y,				KC_U,				KC_I,				KC_O,				KC_P,				\
	LGUI_T(KC_A),		LALT_T(KC_S),		LCTL_T(KC_D),		LSFT_T(KC_F),		KC_G,				KC_H,				LSFT_T(KC_J),		LCTL_T(KC_K),		LALT_T(KC_L),		LGUI_T(KC_QUOT),	\
	LT(U_MOUSE,KC_Z),	KC_X,				KC_C,				KC_V,				KC_B,				KC_N,				KC_M,				KC_COMM,			KC_DOT,				TD(U_TD_SLSH_SCRL),	\
											LT(U_DEBUG,KC_ESC),	LT(U_NAV,KC_SPC),	LT(U_FUN,KC_TAB),	LT(U_SYM,KC_ENT),	LT(U_NUM,KC_BSPC),	KC_DEL

	#define LAYER_NUM \
	KC_LBRC,			KC_7,				KC_8,				KC_9,				KC_RBRC,			KC_NO,				DF(U_BASE),			KC_NO,				KC_NO,				TD(U_TD_BOOT),		\
	KC_SCLN,			KC_4,				KC_5,				KC_6,				KC_EQL,				KC_NO,				KC_LSFT,			KC_LCTL,			KC_LALT,			KC_LGUI,			\
	KC_GRV,				KC_1,				KC_2,				KC_3,				KC_BSLS,			KC_NO,				DF(U_NUM),			DF(U_NAV),			KC_ALGR,			KC_RCTL,			\
											KC_DOT,				KC_0,				KC_MINS,			KC_NO,				KC_NO,				KC_NO

	#define LAYER_SYM \
	KC_LCBR,			KC_AMPR,			KC_ASTR,			KC_LPRN,			KC_RCBR,			KC_NO,				DF(U_BASE),			KC_NO,				KC_NO,				TD(U_TD_BOOT),		\
	KC_COLN,			KC_DLR,				KC_PERC,			KC_CIRC,			KC_PLUS,			KC_NO,				KC_LSFT,			KC_LCTL,			KC_LALT,			KC_LGUI,			\
	KC_TILD,			KC_EXLM,			KC_AT,				KC_HASH,			KC_PIPE,			KC_NO,				DF(U_SYM),			DF(U_FUN),			KC_ALGR,			KC_RCTL,			\
											KC_LPRN,			KC_RPRN,			KC_UNDS,			KC_NO,				KC_NO,				KC_NO


#endif

#define LAYER_NAV \
TD(U_TD_BOOT),		KC_NO,				KC_NO,				DF(U_BASE),			KC_NO,				KC_INS,				KC_HOME,			KC_UP,				KC_END,				KC_PGUP,			\
KC_LGUI,			KC_LALT,			KC_LCTL,			KC_LSFT,			KC_NO,				KC_CAPS,			KC_LEFT,			KC_DOWN,			KC_RGHT,			KC_PGDN,			\
KC_RCTL,			KC_ALGR,			DF(U_NUM),			DF(U_NAV),			KC_NO,				U_RDO,				U_PST,				U_CPY,				U_CUT,				U_UND,				\
										KC_NO,				KC_NO,				KC_NO,				KC_ENT,				KC_BSPC,			KC_DEL

#define LAYER_FUN \
TD(U_TD_BOOT),		KC_NO,				KC_NO,				DF(U_BASE),			KC_NO,				KC_PSCR,			KC_F7,				KC_F8,				KC_F9,				KC_F12,				\
KC_LGUI,			KC_LALT,			KC_LCTL,			KC_LSFT,			KC_NO,				KC_SCRL,			KC_F4,				KC_F5,				KC_F6,				KC_F11,				\
KC_RCTL,			KC_ALGR,			DF(U_SYM),			DF(U_FUN),			KC_NO,				KC_PAUS,			KC_F1,				KC_F2,				KC_F3,				KC_F10,				\
										KC_NO,				KC_NO,				KC_NO,				KC_ENT,				KC_BSPC,			KC_APP

#define LAYER_DEBUG \
KC_NO,				KC_NO,				RESUME,				KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,				\
KC_NO,				STEP_INTO,			STEP_OVER,			STEP_OUT,			KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,				\
KC_NO,				ECLIPSE,			BROWSER,			NEXACRO,			KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,				\
										KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO

#ifdef POINTING_DEVICE_ENABLE
	#define LAYER_MOUSE \
	U_UND,				C(KC_W),			C(KC_E),			C(S(KC_R)),			U_RDO,				DPI_MOD,			U_WINFLT,			U_WINUP,			U_WINFRT,			S_D_MOD,			\
	KC_LGUI,			KC_LALT,			KC_LCTL,			KC_LSFT,			C(KC_H),			U_LFT_DSKT,			U_WINLT,			U_WINDN,			U_WINRT,			U_RGT_DSKT,			\
	KC_NO,				U_CUT,				U_CPY,				U_PST,				KC_NO,				U_NEW_DSKT,			KC_BTN4,			KC_BTN5,			SNIPING,			U_DEL_DSKT,			\
											KC_BTN3,			KC_BTN1,			TD(U_TD_BTN2_SCRL),	KC_BTN2,			KC_BTN1,			KC_BTN3
#else
	#define LAYER_MOUSE \
	U_UND,				C(KC_W),			C(KC_E),			C(S(KC_R)),			U_RDO,				KC_NO,				U_WINFLT,			KC_MS_U,			U_WINFRT,			KC_NO,				\
	KC_LGUI,			KC_LALT,			KC_LCTL,			KC_LSFT,			C(KC_H),			U_LFT_DSKT,			KC_MS_L,			KC_MS_D,			KC_MS_R,			U_RGT_DSKT,			\
	KC_NO,				U_CUT,				U_CPY,				U_PST,				KC_NO,				U_NEW_DSKT,			KC_BTN4,			KC_BTN5,			KC_NO,				U_DEL_DSKT,			\
											KC_BTN3,			KC_BTN1,			KC_BTN2,			KC_BTN2,			KC_BTN1,			KC_BTN3
#endif // POINTING_DEVICE_ENABLE

// 레이어 정의
#define LAYER_LIST \
LAYER_X(BASE,	"Base") \
LAYER_X(NAV,	"Nav") \
LAYER_X(NUM,	"Num") \
LAYER_X(FUN,	"Fun") \
LAYER_X(SYM,	"Sym") \
LAYER_X(MOUSE,	"Mouse") \
LAYER_X(DEBUG,	"Debug")
