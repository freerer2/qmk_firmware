#pragma once

#ifndef NO_DEBUG
	#define NO_DEBUG
#endif // !NO_DEBUG

#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
	#define NO_PRINT
#endif // !NO_PRINT

// 탭홀드, 탭댄스 태핑텀
#undef TAPPING_TERM				//설정 초기화
#define TAPPING_TERM 150		//기본 탭텀 150
#define TAPPING_TERM_PER_KEY	//개별 태핑텀 세팅 허용(get_tapping_term 함수 참고)

// 오토쉬프트
#define NO_AUTO_SHIFT_ALPHA		//알파열 오토쉬프트 미사용
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM //오토쉬프트 적용 시간
#define AUTO_SHIFT_NO_SETUP

// 마우스키
#undef MOUSEKEY_DELAY				//마우스키 딜레이 초기화
#undef MOUSEKEY_INTERVAL			//마우스키 간격 이동시간 초기화
#undef MOUSEKEY_WHEEL_DELAY			//마우스휠 딜레이 초기화
#undef MOUSEKEY_MAX_SPEED			//마우스키 최대속도 초기화
#undef MOUSEKEY_TIME_TO_MAX			//마우스키 최대속도 도달시간 초기화

#define MOUSEKEY_DELAY			0	//마우스키 딜레이 세팅
#define MOUSEKEY_INTERVAL       16	//마우스키 간격 이동시간 세팅
#define MOUSEKEY_WHEEL_DELAY    0	//마우스휠 딜레이 세팅
#define MOUSEKEY_MAX_SPEED      6	//마우스키 최대속도 세팅
#define MOUSEKEY_TIME_TO_MAX    64	//마우스키 간격 세팅

// 마우스 트랙볼
#ifdef POINTING_DEVICE_ENABLE
	#define CHARYBDIS_DRAGSCROLL_REVERSE_Y /*트랙볼 위로 굴리면 스크롤 위로 */
#endif

// 콤보
#define COMBO_TERM 50		//콤보 텀 50
#define EXTRA_SHORT_COMBOS	//콤보조합 최대 6키까지

#define USB_SUSPEND_WAKEUP_DELAY 200 // QMK 20205번 이슈 내용 참고(https://github.com/qmk/qmk_firmware/pull/20205)

//미사용 설정
#define ONESHOT_TAP_TOGGLE 2  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 2000  /* Time (in ms) before the one shot key is released */

// Prevent normal rollover on alphas from accidentally triggering mods.
//#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define QUICK_TAP_TERM 0