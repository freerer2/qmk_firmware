# 슈킹 가이드

해당 키맵을 수정하여 사용 할 때 구현 방법에 대해 설명합니다.

## 목차

- [슈킹 가이드](#슈킹-가이드)
  - [목차](#목차)
  - [콤보](#콤보)
    - [콤보 추가/수정](#콤보-추가수정)
    - [최대 키코드 갯수 변경](#최대-키코드-갯수-변경)
  - [오버라이드](#오버라이드)
    - [오버라이드 추가/수정](#오버라이드-추가수정)
    - [QMK 지원 OVERRIDE에 사용 가능한 MOD키](#qmk-지원-override에-사용-가능한-mod키)
  - [키코드](#키코드)
    - [키코드 추가/수정](#키코드-추가수정)
  - [레이어](#레이어)
    - [레이어 추가/수정](#레이어-추가수정)

## 콤보

### 콤보 추가/수정

콤보 세팅 파일 : [combo_setting.h](../../keymap_helper/settings/combo_setting.h)  
이름, 동작 키코드, 콤보키코드1, 콤보키코드2... 으로 정의

```h
// 예제1) KC_SPC, KC_TAB를 누르면 KC_ESC가 동작함
COMBO_X(left_thumb, KC_ESC, KC_SPC, KC_TAB)

// 예제2) KC_A, KC_B, KC_C, KC_D, KC_E, KC_F를 누르면 KC_ESC가 동작함
COMBO_X(left_thumb, KC_ESC, KC_A, KC_B, KC_C, KC_D, KC_E, KC_F)
```

### 최대 키코드 갯수 변경

-   세팅 파일 : [config.h](../../config.h)  
    `#define EXTRA_SHORT_COMBOS`를 아래의 표에 맞춰 희망하는 값으로 변경

| Keys | Define to be set                  |
| ---- | --------------------------------- |
| 6    | `#define EXTRA_SHORT_COMBOS`      |
| 8    | QMK Default                       |
| 16   | `#define EXTRA_LONG_COMBOS`       |
| 32   | `#define EXTRA_EXTRA_LONG_COMBOS` |

## 오버라이드

### 오버라이드 추가/수정

오버라이드 세팅 파일 : [override_setting.h](../../keymap_helper/settings/override_setting.h)  
이름, 조합할 모드키, 조합할 키코드, 작동 키코드로 정의

```h
// 예제1) 쉬프트 + KC_DOT를 누르면 KC_LT가 동작함
OVERRIDE_X(LT, MOD_MASK_SHIFT, KC_DOT, KC_LT)
```

### QMK 지원 OVERRIDE에 사용 가능한 MOD키
| Mod Mask Name      | Matching Modifiers                             |
|--------------------|------------------------------------------------|
| `MOD_MASK_CTRL`    | LCTRL       , RCTRL                            |
| `MOD_MASK_SHIFT`   | LSHIFT      , RSHIFT                           |
| `MOD_MASK_ALT`     | LALT        , RALT                             |
| `MOD_MASK_GUI`     | LGUI        , RGUI                             |
| `MOD_MASK_CS`      | CTRL        , SHIFT                            |
| `MOD_MASK_CA`      | (L/R)CTRL   , (L/R)ALT                         |
| `MOD_MASK_CG`      | (L/R)CTRL   , (L/R)GUI                         |
| `MOD_MASK_SA`      | (L/R)SHIFT  , (L/R)ALT                         |
| `MOD_MASK_SG`      | (L/R)SHIFT  , (L/R)GUI                         |
| `MOD_MASK_AG`      | (L/R)ALT    , (L/R)GUI                         |
| `MOD_MASK_CSA`     | (L/R)CTRL   , (L/R)SHIFT , (L/R)ALT            |
| `MOD_MASK_CSG`     | (L/R)CTRL   , (L/R)SHIFT , (L/R)GUI            |
| `MOD_MASK_CAG`     | (L/R)CTRL   , (L/R)ALT   , (L/R)GUI            |
| `MOD_MASK_SAG`     | (L/R)SHIFT  , (L/R)ALT   , (L/R)GUI            |
| `MOD_MASK_CSAG`    | (L/R)CTRL   , (L/R)SHIFT , (L/R)ALT , (L/R)GUI |


## 키코드

### 키코드 추가/수정
키코드 세팅 파일 : [keymap_keycode_setting.h](../../keymap_helper/settings/keymap_keycode_setting.h)  
```h
//예제1
enum keycodes {
	STEP_INTO = SAFE_RANGE
	STEP_OVER,
	STEP_OUT,
	RESUME,
};
```

## 레이어

### 레이어 추가/수정
레이어 세팅 파일 : [keymap_layer_setting.h](../../keymap_helper/settings/keymap_layer_setting.h)  