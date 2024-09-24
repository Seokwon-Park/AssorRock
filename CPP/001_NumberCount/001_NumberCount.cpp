#include <iostream>

int NumberCount(int _Value)
{
	int Result = 0;
	while (_Value)
	{
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

	// std::cout << Result0 << '\n' << Result1 << '\n' << Result2 << '\n';

	char Buffer[100] = { 0 };
	NumberToString(Buffer, 100, 31232421);
	// std::cout << Buffer;

	return 0;
}
