# Lazybones

인간은 편한 삶을 위해 발전하며, 모두들 편하게 살기 위해 노력합니다.  
효율적인 사람들은 최소한의 노력으로 최대의 효율을 내기 위해 머리를 씁니다.  
이 키맵은 최소한의 움직임으로 모든것 하고 싶은 자들을 위한 키맵입니다.

## 목차

- [Lazybones](#lazybones)
  - [목차](#목차)
  - [소개글](#소개글)
  - [레이어](#레이어)
  - [컴파일예제](#컴파일예제)
    - [Skeletyl](#skeletyl)
    - [Charybdis Nano](#charybdis-nano)
    - [Lazyboy36](#lazyboy36)
    - [Cator](#cator)
  - [준비중인 기능](#준비중인-기능)
    - [구상중인 기능](#구상중인-기능)
    - [구현중인 기능](#구현중인-기능)
    - [구현된 기능](#구현된-기능)
    - [수정/삭제된 기능](#수정삭제된-기능)

## 소개글

34-36키를 지원합니다.  
하지만 35키(charybdis nano) 또는 36키를 권장합니다.

작성자는  
사무용 : [**Charybdis Nano**](https://github.com/Bastardkb/Charybdis)  
가정용 : [**Skeletyl**](https://github.com/Bastardkb/Skeletyl)  
휴대용 : [**Lazyboy36**](https://github.com/freerer2/keyboard_build/tree/main/lazyboy36)  
비상용 : [**Cantor-remix**](https://github.com/nilokr/cantor-remix)(MX스위치 버전 개조판)  
위 키보드 4개를 주력으로 사용중입니다. 

키맵은 [**miryoku**](https://github.com/manna-harbour/miryoku_qmk/tree/miryoku/users/manna-harbour_miryoku) 를 참고하였습니다.  
또한 C언어를 써본 적이 없으므로 코드의 패턴도 [**miryoku**](https://github.com/manna-harbour/miryoku_qmk/tree/miryoku/users/manna-harbour_miryoku)를 참고하였습니다.  
굳이 C언어를 배울 생각은 없습니다. 소스 구조가 엉망이라도 이해해주세요. 물론 C언어 팁은 환영입니다.

트랙볼의 기능은 charybdis의 기능을 사용하므로 charybdis nano만 지원합니다.

## 레이어

-   [레이어 소개](./docs/layers/layers.md)
-   [슈킹 가이드](./docs/refs/refs.md)

## 컴파일예제

### Skeletyl

```bash
qmk compile -kb bastardkb/skeletyl/blackpill -km lazybones
```

### Charybdis Nano

```bash
qmk compile -kb bastardkb/charybdis/3x5/blackpill -km lazybones
```

### Lazyboy36

```bash
qmk compile -kb lazyboy36/rp2040 -km lazybones
```

### Cator

```bash
qmk compile -kb cantor -km lazybones
```

<!-- ### qmk compile -kb bastardkb/skeletyl/blackpill -km lazybones -e DOUBLE_B=yes -->
<!-- ### qmk compile -kb bastardkb/charybdis/3x5/blackpill -km lazybones -e DOUBLE_B=yes -->

## 준비중인 기능

### 구상중인 기능

-   양손 B키 삽입을 생각중입니다.  
    솔직히 `/`를 특수문자 레이어로 옮기고  
    `Z` `X` `C` `V` `B` | `B` `N` `M` `,` `.`  
    순으로 배치하면, 양손으로 B키를 쓸 수 있을 것 같아서 구상중입니다.  
    사실 이전에 했었다가 적응에 실패했는데 다시 해볼 생각을 하고 있습니다.

### 구현중인 기능

-   없음

### 구현된 기능

-   콤보 추가를 매크로로 할 수 있게 했습니다.  
    디시인사이드 스플릿 키보드 갤러리에서 우연히 [이글](https://gall.dcinside.com/mini/board/view/?id=splitkeeb&no=1507)을 보고 구현하였습니다.  
    덕분에 미료쿠의 레이어가 매크로라는 기능으로 정의 된다는 것을 깨달았습니다.
-   override 기능 추가를 매크로로 할 수 있게 했습니다.  
    콤보 추가로 깨달음을 얻어 오버라이드까지 추가했습니다.

### 수정/삭제된 기능

-   2024-04-08 : `Shift + Space` 조합 포기 `KC_ALGR`, `KC_RCTL` 사용
-   2024-04-05 : 기존 미료쿠의 레이어 더블탭 기능을 삭제하였습니다.  
    DF()로 수정하였습니다. 잘못 누르는 경우 좀 빡치겠지만, 한손으로 뭐 하는데 두번 씩 누르면 킹받잖아요.
-   기존 미료쿠에서 무언가 많이 바뀌었습니다.
