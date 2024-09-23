// 030_Return.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// int  함수 이름 앞에 존재하는 자료형을 리턴 값이라고 부릅니다.
// 리턴값이 존재하게 되면 리턴을 안하면 함수가 성립하지 못하게 됩니다.
int ReturnFunction()
{
    // return 외부에 메모리영역을 준비해라.
    // 나는 4바이트 정수를 리턴할 것이다.
    return 100;
}

int Test()
{
    return 100/*자료형에 맞는 메모리영역*/;
}

int TestError()
{
    // 자료형의 암시적 형변환이 안되거나
    // 전혀 맞지 않는 자료형을 리턴할수는 없다.
    // return nullptr;
    return 100;
}

    // void => 비어있다 => 메모리영역이 존재하지 않는다.
    // return 을 생략해도 된다.;

void voidReturnFunction()
{
    return;
}

void ReturnFunctionEnd1()
{
    // { <= 스택의 시작
    //    return
    // }

    return;
}

void ReturnFunctionEnd()
{
    // 리턴하는 순간 참고로 그 함수 함수는 즉각 종료됩니다.
    // 어떤 상황에서든 {  } 안의 메모리를 모조리 파괴하고
    // 함수는 종료됩니다.
    return;
    int a = 0;
}

// 리턴값은 무조건 1개의 자료형만 리턴할수 있습니다.
// 불가능이니까. 
int Test1111()
{
    return 10;
}


int main()
{
    // 눈에 보이지는 않지만 여기에는 4바이트가 존재한다.
    Test();
}
