#pragma once

#define U_UND C(KC_Z)
#define U_RDO C(KC_Y)
#define U_PST C(KC_V)
#define U_CPY C(KC_C)
#define U_CUT C(KC_X)

#define U_WINLT G(KC_LEFT)
#define U_WINUP G(KC_UP)
#define U_WINDN G(KC_DOWN)
#define U_WINRT G(KC_RGHT)

#define U_WINFLT G(S(KC_LEFT))
#define U_WINFUP G(S(KC_UP))
#define U_WINFDN G(S(KC_DOWN))
#define U_WINFRT G(S(KC_RGHT))

#define U_NEW_DSKT G(C(KC_D))
#define U_DEL_DSKT G(C(KC_F4))
#define U_LFT_DSKT G(C(KC_LEFT))
#define U_RGT_DSKT G(C(KC_RGHT))

#ifdef POINTING_DEVICE_ENABLE
#	ifndef NO_CHARYBDIS_KEYCODES
#		define DPI_MOD POINTER_DEFAULT_DPI_FORWARD
#		define DPI_RMOD POINTER_DEFAULT_DPI_REVERSE
#		define S_D_MOD POINTER_SNIPING_DPI_FORWARD
#		define S_D_RMOD POINTER_SNIPING_DPI_REVERSE
#		define SNIPING SNIPING_MODE
#		define SNP_TOG SNIPING_MODE_TOGGLE
#		define DRGSCRL DRAGSCROLL_MODE
#		define DRG_TOG DRAGSCROLL_MODE_TOGGLE
#	endif // !NO_CHARYBDIS_KEYCODES
#endif // POINTING_DEVICE_ENABLE

// 유저키코드 나열
enum user_keycodes {
	ECLIPSE,
	BROWSER = SAFE_RANGE,
	NEXACRO,
	STEP_INTO,
	STEP_OVER,
	STEP_OUT,
	RESUME,
	A_A,
	B_A,
	C_A,
	D_A,
	E_A,
	A_B,
	B_B,
	C_B,
	D_B,
	E_B,
	A_C,
	B_C,
	C_C,
	D_C,
	E_C,
};

// 더블탭 키코드 나열
enum double_tab_keycodes {
	U_TD_BOOT,
	U_TD_SLSH_SCRL,
	U_TD_BTN2_SCRL,
};