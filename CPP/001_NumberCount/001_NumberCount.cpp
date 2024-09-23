// 001_NumberCount.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int NumberCount(int _Value)
{
	int Result = 0;
	while (true)
	{
		if (_Value == 0)
			break;
		Result++;
		_Value /= 10;
	}
	return Result;
}

void NumberToString(char* Buffer, int BufferSize, int _Value)
{
	int Size = NumberCount(_Value);

	for(int i = Size - 1; i >= 0; i--)
	{
		Buffer[i] = _Value % 10 + '0';
		_Value /= 10;
	}
}

int main()
{
	//5
	int Result0 = NumberCount(12358);
	//4
	int Result1 = NumberCount(5258);
	//7
	int Result2 = NumberCount(5258111);

	//std::cout << Result0 << '\n' << Result1 << '\n' << Result2;

	char Buffer[100] = { 0 };
	NumberToString(Buffer, 100, 31232421);

	return 0;
}
