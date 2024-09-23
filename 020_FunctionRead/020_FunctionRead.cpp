#include <iostream>

// 제대로된 프로그래머라면 
// 실행을 못시킨다는것은 말이 안된다.
// 어떤 함수를 봤는데 못 쓴다는 

void MyPrintf(char* Arr)
{
	int Result = 0;
	// 코드가 반복적이다.
	Result = putchar(Arr[0]);
	Result = putchar(Arr[1]);
	Result = putchar(Arr[2]);
	Result = putchar(Arr[3]);
	Result = putchar(Arr[4]);
}

int main()
{
	// 새로운 함수를 하나 보여드리겠습니다.
	// 모든 함수를 내부까지 다 구현하면서 보여줄수가 없다.
	// 함수는 도구이다.
	// 자동차 탄다고 엔진설계를 알아야하나요?
	// 타이어 만드는법 알아야 하는게 아니다.
	// 그 함수의 의도를 읽어나 의도를 모르더라도 실행을 해보고
	// 결과나 이런 걸로 추론하는 능력은 필수다.

	// int A = 10;

	char Arr[5] = "ABCD";

	// 코드를 읽을때는 오른쪽부터 읽어야 한다.


	MyPrintf(Arr);

}
