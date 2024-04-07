# Lazybones

인간은 편한 삶을 위해 발전하며, 모두들 편하게 살기 위해 노력합니다.  
효율적인 사람들은 최소한의 노력으로 최대의 효율을 내기 위해 머리를 씁니다.  
이 키맵은 최소한의 움직임으로 모든것 하고 싶은 자들을 위한 키맵입니다.

## 소개글

34-36키를 지원합니다.  
하지만 35키(charybdis nano) 또는 36키를 권장합니다.  
C언어를 써본 적이 없으므로 코드의 패턴은 miryoku를 참고하였습니다.

굳이 C언어를 배울 생각은 없습니다. 소스 구조가 엉망이라도 이해해주세요. 물론 C언어 팁은 환영입니다.

작성자는  
사무용으로 [**Charybdis Nano**](https://github.com/Bastardkb/Charybdis)를 사용하고  
가정용으로 [**Skeletyl**](https://github.com/Bastardkb/Skeletyl)을 사용하며  
휴대용으로 [**Cantor-remix**](https://github.com/nilokr/cantor-remix)를 MX버전으로 개조하여 사용중입니다.  
트랙볼의 기능은 charybdis의 기능을 사용하므로 charybdis nano만 지원합니다.

## 링크
> [레이어 소개](./docs/layers/layers.md)  
> ~~[슈킹 가이드](./docs/refs/refs.md)(작성중)~~ 누가 물어보면 그 때 작성하는걸로

## 컴파일예제

### Skeletyl
qmk compile -kb bastardkb/skeletyl/blackpill -km lazybones

### Charybdis Nano
qmk compile -kb bastardkb/charybdis/3x5/blackpill -km lazybones

### Cntor
qmk compile -kb cantor -km lazybones

<!-- ### qmk compile -kb bastardkb/skeletyl/blackpill -km lazybones -e DOUBLE_B=yes -->
<!-- ### qmk compile -kb bastardkb/charybdis/3x5/blackpill -km lazybones -e DOUBLE_B=yes -->

## 준비중인 기능

### 구상중인 기능
- 양손 B키 삽입을 생각중입니다.  
솔직히 `/`를 특수문자 레이어로 옮기고  
`Z` `X` `C` `V` `B` | `B` `N` `M` `,` `.`  
순으로 배치하면, 양손으로 B키를 쓸 수 있을 것 같아서 구상중입니다.  
사실 이전에 했었다가 적응에 실패했는데 다시 해볼 생각을 하고 있습니다.

### 구현중인 기능
- 없음

### 구현된 기능
- 콤보 추가를 매크로로 할 수 있게 했습니다.  
디시인사이드 스플릿 키보드 갤러리에서 우연히 [이글](https://gall.dcinside.com/mini/board/view/?id=splitkeeb&no=1507)을 보고 구현하였습니다.  
덕분에 미료쿠의 레이어가 매크로라는 기능으로 정의 된다는 것을 깨달았습니다.
- override 기능 추가를 매크로로 할 수 있게 했습니다.  
콤보 추가로 깨달음을 얻어 오버라이드까지 추가했습니다.

### 수정/삭제된 기능
- 기존 미료쿠에서 무언가 많이 바뀌었습니다.  
- 기존 미료쿠의 레이어 더블탭 기능을 삭제하였습니다.(2024-04-05)  
DF()로 수정하였습니다. 잘못 누르는 경우 좀 빡치겠지만, 한손으로 뭐 하는데 두번 씩 누르면 킹받잖아요.  
