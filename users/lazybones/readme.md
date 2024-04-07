# lazybones

인간은 편한 삶을 위해 발전하며, 모두들 편하게 살기 위해 노력합니다.  
효율적인 사람들은 최소한의 노력으로 최대의 효율을 내기 위해 머리를 씁니다.  
이 키맵은 최소한의 움직임으로 모든것 하고 싶은 자들을 위한 키맵입니다.

## 소개글

34-36키를 지원합니다.  
하지만 35키(charybdis nano) 또는 36키를 권장합니다.  
C언어를 써본 적이 없으므로 코드의 패턴은 miryoku를 참고하였습니다.

작성자는  
사무용으로 [**Charybdis Nano**](https://github.com/Bastardkb/Charybdis)를 사용하고  
가정용으로 [**Skeletyl**](https://github.com/Bastardkb/Skeletyl)을 사용하며  
휴대용으로 [**cantor-remix**](https://github.com/nilokr/cantor-remix)를 MX버전으로 개조하여 사용중입니다.  
트랙볼의 기능은 charybdis의 기능을 사용하므로 charybdis nano만 지원합니다.

## 목차
> [레이어](#레이어)  
> > [베이스(Base) 레이어](#베이스(Base)-레이어)  
> > [이동(Nav) 레이어](#이동(Nav)-레이어)  
> > [기능(Fun) 레이어](#기능(Fun)-레이어)  
> > [숫자(Num) 레이어](#숫자(Num)-레이어)  
> > [특문(Sym) 레이어](#특문(Sym)-레이어)  
> > [마우스(Mouse) 레이어-트랙볼 지원](#마우스(Mouse)-레이어-트랙볼-지원)  
> > [마우스(Mouse) 레이어-트랙볼 미지원](#마우스(Mouse)-레이어-트랙볼-미지원)  
>
> [주요 구현 기능](#주요-구현-기능)  

## 레이어

### 베이스(Base) 레이어

![base](/users/lazybones/docs/layers/base.svg)

### 이동(Nav) 레이어

![nav](/users/lazybones/docs/layers/nav.svg)

### 기능(Fun) 레이어

![fun](/users/lazybones/docs/layers/fun.svg)

### 숫자(Num) 레이어

![num](/users/lazybones/docs/layers/num.svg)

### 특문(Sym) 레이어

![sym](/users/lazybones/docs/layers/sym.svg)

### 마우스(Mouse) 레이어-트랙볼 지원

![mouse_with_trackball](/users/lazybones/docs/layers/mouse_with_trackball.svg)

### 마우스(Mouse) 레이어-트랙볼 미지원

![mouse_without_trackball](/users/lazybones/docs/layers/mouse_without_trackball.svg)

## 주요 구현 기능

레이어 변환, 콤보, 탭댄스(상세내용 작성예정)

### 콤보

-   rules.mk

```make
COMBO_ENABLE = yes
```

-   config.h

```h
#define COMBO_TERM 50		//콤보 텀 50
#define EXTRA_SHORT_COMBOS	//콤보조합 최대 6키까지
```

-   lazybones.h

```h
//콤보 정의(이름, 작동키, 콤보키)
#define COMBO_LIST \
COMBO_X(left_thumb,		KC_ESC,		LT(U_NAV,KC_SPC),	LT(U_FUN,KC_TAB)) \
COMBO_X(mouse_thumb,	KC_BTN3,	KC_BTN1,			KC_BTN2) \
COMBO_X(right_thumb,	KC_DEL,		LT(U_SYM,KC_ENT),	LT(U_NUM,KC_BSPC)) \
COMBO_X(XC,				KC_UNDS,	KC_X,				KC_C) \
COMBO_X(SD,				S(KC_SPC),	LALT_T(KC_S),		LCTL_T(KC_D)) \
COMBO_X(KL,				KC_CAPS,	LCTL_T(KC_K),		LALT_T(KC_L))
```

-   lazybones.c

```c
// 콤보 목록 나열
enum combos {
	#define COMBO_X(NAME, WORK_KEY, ...) NAME,
		COMBO_LIST
	#undef COMBO_X
};

// 콤보 키 배열 정의
#define COMBO_X(NAME, WORK_KEY, ...) const uint16_t PROGMEM COMBO_##NAME[] = {__VA_ARGS__, COMBO_END};
	COMBO_LIST
#undef COMBO_X

// 콤보 동작키 매핑
combo_t key_combos[] = {
	#define COMBO_X(NAME, WORK_KEY, ...) [NAME] = COMBO(uint16_t PROGMEM COMBO_##NAME, WORK_KEY),
		COMBO_LIST
	#undef COMBO_X
};
```

상세내용 작성예정

### 홀드/탭

상세내용 작성예정

### 한손사용 레이어 변환

상세내용 작성예정

### 기타

상세내용 작성예정

#

## Example

### qmk compile -kb bastardkb/skeletyl/blackpill -km lazybones

### qmk compile -kb bastardkb/charybdis/3x5/blackpill -km lazybones

### qmk compile -kb cantor -km lazybones

<!-- ### qmk compile -kb bastardkb/skeletyl/blackpill -km lazybones -e DOUBLE_B=yes -->
<!-- ### qmk compile -kb bastardkb/charybdis/3x5/blackpill -km lazybones -e DOUBLE_B=yes -->

![](/users/lazybones/docs/freerer2.svg)

# 준비중인 기능

## 구상중인 기능

-   양손 B키 삽입

## 구현중인 기능

-   없음

## 구현된 기능

-   없음

## 삭제된 기능

-   없음
