// 023_WhileFor_Test.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	// A B C D 0
    // char Arr[5] = "ABCD";


	{
		// 나중에 다시 자세히 배워 보겠습니다.
		char Arr[5] = { 'A', 'B', 'C', 'D', 0 };

		// ranged for인데 초반에 왠만하면 안쓰겠습니다.
		for (char Ch : Arr)
		{
			putchar(Ch);
		}
	}


	{
		char Arr[5] = { 'A', 'B', 'C', 'D', 'E' };

		printf_s(Arr);

		printf_s("\n");

		int i = 0;
		char ChTest = 0;
		while (
			Arr[i]
			)
		{
			ChTest = Arr[i];
			putchar(ChTest);
			i += 1;
		}
	}

	{
		char Arr[5] = { 'A', 'B', 'C', 'D', 'E' };

		int i = 0;
		char ChTest = 0;
		for (
			int i = 0; 
			Arr[i]; 
			i += 1
			)
		{
			ChTest = Arr[i];
			putchar(ChTest);
		}
	}


}
