#include <iostream>

int main()
{
	{
		int Value = 1;
		int Value0 = 1;
		if (Value0 >= Value)
		{

		}
	}

	{
		// switch문은 온전히 if 대체될수 있습니다.
		// if문은 switch문으로 대체할수 없다. 

		// switch_on 메모리영역을 넣는다.
		// 상수와만 비교를 합니다.

		{
			int Value = 1;
			int Value0 = 1;
			switch (Value)
			{
			case 1:
			{
				int a = 0;
				printf_s("Value는 1입니다");
				break;
			}
			default: // else의 역할을 합니다.
			{
				printf_s("맞는 조건이 없었습니다");
				break;
			}
			}
		}

		{
			int Value = 1;
			int Value0 = 1;
			if (1 == Value)
			{
				int a = 0;
				printf_s("Value는 1입니다");
			}
			else
			{
				printf_s("맞는 조건이 없었습니다");
			}
		}
	}

	{
		// 스위치 문을 왜쓰나요?
		// 자동완성이 편하다.

		enum class MyEnum
		{
			Fighter,
			Archer,
			Mage
		};
		MyEnum Test;
		switch (Test)
		{
		case MyEnum::Fighter:
			break;
		case MyEnum::Archer:
			break;
		case MyEnum::Mage:
			break;
		default:
			break;
		}
	}
}
