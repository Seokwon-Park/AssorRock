// 031_Random.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int Seed = 0;

// 시드값을 변경하는 함수
void MySrand(int _Value)
{
	Seed = _Value;
}

// 그 시드값을 통해서 난수를 만들어내는 함수
int MyRand()
{
	Seed += 1;
	return Seed;
}

int main()
{
	// char 

	// 일반적으로 2가지 방법이 존재합니다.

	// 그리니치 천문대
	// 1976년 4바이트 정했습니다.
	// 그런느낌으로 정수가 나온다.
	__int64 Value = time(nullptr);
	srand(100);

	for (int i = 0; i < 10; i++)
	{
		// 
		std::cout << rand() << std::endl;
	}
}

