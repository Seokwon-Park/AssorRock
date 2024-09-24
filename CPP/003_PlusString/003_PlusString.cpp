#include <iostream>

int StringCount(const char* const _Str)
{
	int Count = 0;

	while (_Str[Count])
	{
		Count++;
	}

	return Count;
}

void PlusString(char* _Buffer, int BufferSize, const char* const _Value0, const char* const _Value1)
{
	int ix = 0;
	int _Value0Size = StringCount(_Value0);
	for(int i = 0; i< _Value0Size; i++)
	{
		_Buffer[ix] = _Value0[i];
		ix += 1;
	}

	int _Value1Size = StringCount(_Value1);
	for (int i = 0; i < _Value1Size; i++)
	{
		_Buffer[ix] = _Value1[i];
		ix += 1;
	}
}
int main()
{
	char Arr[100] = {};

	PlusString(Arr, 100, "AAAA", "BBBB");

	std::cout << Arr;
}

