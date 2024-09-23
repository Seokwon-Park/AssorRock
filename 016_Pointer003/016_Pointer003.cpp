// 016_Pointer003.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 포인터에도 비슷한 연산자가 있습니다.

// 가변인자는 선생님이 별로 좋아하지 않는 문법이고
// 많이 사용하지 않는 문법입니다.
// 그런데 왜했냐? 문법은 선택하는게 아니라는 생각이 있고.
// 문법에 의미부여하지 마세요.
// ㄱㄴㄹㄷ 의미부여하는 겁니다.

//void Test(bool _Value0, bool _Value1, bool _Value2)
//{
//}

void Test(bool _Value0, ...)
{
    bool* Ptr = &_Value0;

    // Ptr + 1;
    // Ptr + sizeof(bool) * 1;

    bool Result0 = Ptr[0];
    bool Result1 = Ptr[8];
    bool Result2 = Ptr[16];
    bool Result3 = Ptr[24];
}

int main()
{
    Test(true, false, true, false);

    // 4바이트 단위
    // [0][][][][][][][10]

    //  100
    int Value0 = 11;
    int Value1 = 99;

    __int64 Add0 = reinterpret_cast<__int64>(&Value0);
    __int64 Add1 = reinterpret_cast<__int64>(&Value1);


    // 복잡하고 잘 읽히지가 않고
    // 특정위치로 이동하고 그곳의 값을 사용하고 싶다.

    int Result0 = *((&Value0) + 8);

    int* Ptr = (&Value0) + 8;

    int* PtrValue0 = &Value0;
    // int Result1 = (&Value0)[8];

    // Value0의 주소에서 + 8(32번지 이동) 만큼 
    // 그곳에 값을 사용한다.
    // int* Value0MovePtr = (&Value0) + 8;
    // *(Value0MovePtr)
    int Result1 = PtrValue0[8];

    // 
    // int Result1 = PtrValue0[정수];

    int Result10 = PtrValue0[-2];

    int a = 0;
    
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
// 
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
