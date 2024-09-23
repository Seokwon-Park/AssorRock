// 012_Cast.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	// 자료형이 의미없다는 이야기를 선생님이 많이하지만
	// 비트 덩어리로 봅니다.
	// 바이트의 크기만 있을뿐 전부다 비트 덩어리입니다.

	// 상수도 bool 
	// 그걸 받는 변수도 bool
	// => 형을 유지했다라고 말한다.
	bool Test = true;

	// 언제든지 바이트 단위로 메모리영역으 변환시킬수 있다고 생각합니다.
	// 나도 모르게 사용하는 경우도 많지만
	// 문제가 되는 경우가 문제가 되지 않는 상황이 있다.
	// 그리고 되도록이면 명시적인 형변환 연산자를 통해서
	// 형변환을 하는것을 추천합니다.
	
	// 형변환이다.
	//int         bool
	// 아래와 같이 해줘야 정석이다.
	// int Testint = static_cast<int>(true);
	// bool 이 int가 됐고 그걸 C++이 허용했는데.
	// 이때 명시적이지 전부다 암시적 형변환입니다.
	// 되도록이면 하지 않으려고 노력합니다.
	
	// 1. 바이트가 작은 형을 바이트가 큰형에 넣을때는 문제가 보통 없습니다.
	//  4         1
	int Testint = true;

	// 손실되었더라고 합니다.
	// 123456 복구할수 있냐? 보통 복구할수 없어요.
	// 큰 바이트를 작은 바이트에 넣으면 복구할수가 없다.
	// 그래서 메모리를 잃어버렸다고 표현하고
	// 보통 하지마라...
	// bool TestBool = 123456;
	
	// 이러한 형변환 방법에는
	// C 스타일
	// C++ 스타일이 존재합니다.
	// C 스타일은 
	// 암시적형변환과 
	
	// c스타일 명시적 형변환
	// bool TestBool = (bool)123456;

	// C++에서는 이것도 나눠야 한다.
	// 4가지 캐스트가 있고
	// 그중 오늘 2가지 캐스트를 확인하겠습니다.

	// static_cast
	// reinterpret_cast

	// 값대 값 변화 메모리크기에 변화가 있을때 명시해주라는 의미의 캐스트입니다.
	// static_cast
	
	// bool TestBool = 123456;
	// bool TestBool = (bool)123456;
	bool TestBool = static_cast<bool>(123456);

	// 주소값을 다른 무언가로 변환할때는 reinterpret_cast
	// bool* => int* 특정 포인터를 다른 자료형의 포인터로 변환
	// int* => int 포인터를 정수로 변환
	// int => int* 정수를 포인터로 변환

	// 임의의 주소는 하지 않습니다.
	// int* Ptr = reinterpret_cast<int*>(65635634663);

	// ????? 랜덤 ?????
	// *Ptr = 200;

	// 8바이트 정수입니다.
	// __int64; => 명확하게 64비트 즉 8바이트 정수라는게 보여서 이걸 선호합니다.
	// long long;

	int Test000 = 0;
	int Test001 = 0;
	int Test002 = 0;

	unsigned __int64 Address000 = reinterpret_cast<unsigned __int64>(&Test000);
	unsigned __int64 Address001 = reinterpret_cast<unsigned __int64>(&Test001);
	unsigned __int64 Address002 = reinterpret_cast<unsigned __int64>(&Test002);

	unsigned __int64 Inter0 = Address002 - Address001;
	unsigned __int64 Inter1 = Address001 - Address000;

	int a = 0;

	// 추후 배울 캐스트
	//dynamic_cast
	//const_cast


}



