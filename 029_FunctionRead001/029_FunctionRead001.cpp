// 029_FunctionRead001.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 함수의 종류는 다음과 같다.
// const는 대체 언제 붙여야 하나요?

// 반환값에 의미가 담겨 있는 경우

// 1. 리턴값이 중요한 함수
// int StringCount(인자);
// int <= 이함수의 결과를 알수가 있다.
// 리턴값을 기반으로 함수

// const가 붙지 않음 참조형이 들어간 함수들
// 2. 값을 바꿔서 너에게 주겠다.
// void StringCount(int* Ptr);
// void StringCount(int& Ptr);


void Test(const int* Ptr)
{
    // *Ptr = 300;
}

// 리턴값에는 cosnt 
const int ReturnValue()
{
    return 100;
}

void PlayerHPCheck(int& Ptr)
{
    Ptr = 100;
}

int PlayerHPCheckPtr(int* Ptr)
{
    if (nullptr != Ptr)
    {
    }
}

// 어떤 메모리영역을 넣어주면
// 그 메모리영역을 바꾸지도 않을것이고
// 그 주소값을 이동시키커나 변화시키지도 않을것이다.
//void MyPrintf(char* Ptr)
//{
//    // Ptr = nullptr;
//    // Ptr[0] = 'B';
//    Ptr[2] = '3';
//}

void ValueFunction(int Ptr)
{

}





int main()
{

    {
        int Value = ReturnValue();

        int a = 0;
    }

    {
        // int& PlayerHP;

        int TestValue = 0;
        PlayerHPCheck(TestValue);
        PlayerHPCheck(TestValue);
        PlayerHPCheckPtr(nullptr);
    }

    {
        char Test[10] = "AAA";

        // printf_s(Test);
        // MyPrintf(Test);
        
        int a = 0;
    }

    {
        // printf_s();
        // 오늘*
        // 오늘&
    }

    {
        // C
    }
}

