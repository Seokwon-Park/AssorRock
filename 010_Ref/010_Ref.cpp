// 010_Ref.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void PlayerSaveFileLoad()
{

}

void CreatePlayerValue(int _PlayerHp, int _PlayerAtt)
{
    _PlayerHp = 3000;
    _PlayerAtt = 200;
}

void CreatePlayerPtr(int* _PlayerHp, int* _PlayerAtt)
{
    *_PlayerHp = 100;
    *_PlayerAtt = 50;

    // _PlayerHp = 20;
}

void CreatePlayerRef(int& _PlayerHp, int& _PlayerAtt)
{
    _PlayerHp = 3000;
    _PlayerAtt = 200;
}

int main()
{
    int PlayerHp = 0;
    int PlayerAtt = 0;
    CreatePlayerValue(PlayerHp, PlayerAtt);

    // 다음과 같이 인자와 같은 자료형이 될수 없다면
    // 애초에 함수에도 들어갈수 없다.
    // int* _PlayerHpPtr = &PlayerHp;
    // int* _PlayerAttPtr = &PlayerAtt;
    CreatePlayerPtr(&PlayerHp, &PlayerAtt);

    // 레퍼런스는 그냥 포인터의 한 변형이라고 보시면 됩니다.
    //int& _PlayerHp = PlayerHp;
    //int& _PlayerAtt = PlayerAtt;
    CreatePlayerRef(PlayerHp, PlayerAtt);

    // PlayerHp = 100;
    // PlayerAtt = 20;


    int A = 20;
    // 300번지

    int* APtr = &A;
    // 350번지 

    // ARef 는 상시 *붙여서 사용하는 포인터
    int& ARef = A;
    // 400번지

    *APtr = 30;

    // 포인터를 사용한다는 것과 동일하다.
    ARef = 30;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
