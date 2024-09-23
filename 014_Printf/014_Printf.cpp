// 014_Printf.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// #include <iostream>
#include <stdio.h>

//extern "C" inline int __cdecl printf_s(const char* const _Format, ...)
//{
//}

// 가변인자라고 합니다.

// 이게 어떻게 동작하나요?
// 가변인자 함수에서 
// 첫번째 규칙은 가변인자만 사용하면 안된다.
// 무조건 첫번째 인자가 있어야 가변인자를 사용할수 있다.
// void MyPrint(int Count, ...)

void MyPrint(int Count, ...)
// void MyPrint(int Count, int Value0, int Value1, int Value2)
{
	int* FirstAddress = &Count;

	__int64 Address = reinterpret_cast<__int64>(FirstAddress);
	Address = Address + 8;
	int* SecAddress = reinterpret_cast<int*>(Address);

	int a = 0;

}

void TestFunction(int Value)
{

}

int main()
{
	// 가변인자나 printf같은 c스타일 함수들은
	// 기본적으로 프로그래머의 실력과 주의력. 꼼꼼함을 기반으로 한다.
	// 최신 문법들은 그걸 허용해서 인간의 주의력은 믿을수 없다.

	MyPrint(10, 99, 1, 2);

	// 인자 개수 자유 자료형 자유 마음대로 넣어도 동작합니다.
	// MyPrint(10, 20, 30, 40, 50, 222, true, false, true, false);

	// int Value = 10;
	// int Value0 = 10;
	// TestFunction(Value, Value0);


	// ro메모리
	// "fasdfsadfsad";

	// printf_s(...);
}
