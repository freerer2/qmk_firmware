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
	A_A_A,
	A_B_A,
	A_C_A,
	A_D_A,
	A_E_A,
	A_A_B,
	A_B_B,
	A_C_B,
	A_D_B,
	A_E_B,
	A_A_C,
	A_B_C,
	A_C_C,
	A_D_C,
	A_E_C,
	B_A_A,
	B_A_B,
	B_A_C,
	B_B_A,
	B_B_B,
	B_B_C,
	B_C_A,
	B_C_B,
	B_C_C,
	B_D_A,
	B_D_B,
	B_D_C,
	B_E_A,
	B_E_B,
	B_E_C,
	B_F_A,
	B_F_B,
	B_F_C,
	B_G_A,
	B_G_B,
	B_G_C,
	B_H_A,
	B_H_B,
	B_H_C,
	B_I_A,
	B_I_B,
	B_I_C,
	B_J_A,
	B_J_B,
	B_J_C,
};

// 더블탭 키코드 나열
enum double_tab_keycodes {
	U_TD_BOOT,
	U_TD_SLSH_SCRL,
	U_TD_BTN2_SCRL,
};