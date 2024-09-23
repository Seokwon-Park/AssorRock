// 024_if.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	{
		// 조건문이 true이면 내부코드를 실행한다.
		// 메모리영역의 값이 참이면 내부코드 실행
		// 거짓이면 내부코드 를 실행하지 않는다.
		int Value = 1;

		// Value == 0이면 내부코드를 실행해라.
		if (printf_s("조건체크"), Value = 0);
		{
			printf_s("내부코드 실행");
		}


	}

	{
		int Value = 1;

		// Value == 0이면 내부코드를 실행해라.
		if (printf_s("조건체크"), 1 == Value);
		{
			printf_s("내부코드 실행");
		}

	}

	{
		int Value = 1;
		if (1 == Value)
			printf_s("내부코드 실행");

		//while (true)
		//	printf_s("내부코드 실행");
	}

	{
		int Value = 1;
		if (0 == Value)
		{
			printf_s("0 == Value 내부코드 실행");
		}
		// if아래 }뒤에 있으면 된다.
		else // 상위 모든 조건이 false일시 
		{
			// else는 무조건 넣어야 하는 구문이 아닙니다.
			printf_s("else 내부코드 실행");
		}
	}

	{
		// if를 여러개를 걸수가 있는데
		int Value = 1;
		if (0 == Value)
		{
			printf_s("0 == Value 내부코드 실행");
		}

		// 여기서부터는 새로운 if
		if (1 == Value) 
		{
			// 추가 else if 아무리 많아도 그중 조건에 맞는 1개의
			// else if 내부로 들어왔다면 이 연속되
			// if문 바깥으로 나가게 된다.
			printf_s("1 == Value 내부코드 실행0");
		}
		else if (1 == Value) // 추가 else if 아무리 많아도 
		{
			printf_s("1 == Value 내부코드 실행1");
		}
			 // else는 가장 아래 있어야 합니다.
		else // 상위 모든 조건이 false일시 
		{
			printf_s("else 내부코드 실행");
		}

		// if문 여러개가 중첩되어서
		// 1. 최상위는 무조건 그냥 if여야 한다. 
		// ex) else if로는 시작할수 없다.
		// 2. 조건에 맞는게 여러개가 있어도 위쪽 if부터 체크한다
		// 3. 하나의 true라도 있으면 그 ture의 내부코드가 실행되고
		//    나머지 모든 문장은 무시 된다.
	}

}
