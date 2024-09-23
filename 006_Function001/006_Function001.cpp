// 006_Function001.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 함수에는 인자를 넣어줄수 있다.
// 선생님의 스탠다드는
// 함수인자에는 _붙이는 것을 선호합니다.
// 그 이외에 함수의 이름은 무조건 맨 앞글자는 대문자로 합니다.
// 속력이 빨라진다. 함수이름 같은거에 고민안한다.
// 그 이외에 코딩 자체가 규격화가 된다.


// 함수의 인자에 대해서 이해해 보자.
int Minus(int _Value0, int _Value1)
{
    // 진짜 그 결과값이 바깥에 전달되를 원하게 됩니다.
    // 그때 사용되는것이 리턴값입니다.
    // 리턴값의 자료형 이름(인자)

    // 인자는 지역변수로 판정됩니다.
    // int _Left, int _Right

    return _Value0 - _Value1;
}


// 이때 void는 리턴 안할거다.
// => main함수 입장에서는 void인 함수는
//   결과값을 받을필요가 없으므로 공간을 만들 필요가 없게된다.

void Test()
{
    return;
}


int main()
{
    // int Result = Test();

    int Left = 3;
    int Right = 5;

    // 보이지 않는 int가 존재합니다.
    // int Result;

    /*int Result = */;

    // 무슨일이 벌어지는가?
    // 함수의 리턴값에는 위치와 크기는 있습니다.
    // LValue = RValue 
    // Lvalue는 명확하게 이름과 주소가 확정되어서 문법적으로
    // 확인할수 있는 값만이 LValue가 될수 있다.
    Minus(Left, Right);
    Left - Right;

    // int Result = ;

}
