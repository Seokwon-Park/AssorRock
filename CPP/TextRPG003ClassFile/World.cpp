#include "World.h"
#include "FightZone.h"
#include "Town.h"
#include <conio.h>
#include "Player.h"


void UWorld::InPlayer(class UPlayer& _Player)
{
	char InputName[100] = {0,};

	while (true)
	{
		system("cls");

		std::cout << "�̸��� �����ּ���" << std::endl;
		std::cin >> InputName;

		printf_s("����� �̸��� %s�Դϴ�. �����Ͻðڽ��ϱ�?\n", InputName);
		printf_s("a. ����\n");
		printf_s("b. ���Է�\n");
		bool IsEnd = false;
		bool isValid = false;
		while (!isValid)
		{
			int Select = _getch();
			switch (Select)
			{
			case 'a':
			case 'A':
				isValid = true;
				IsEnd = true;
				_Player.SetName(InputName);
				break;
			case 'b':
			case 'B':
				isValid = true;
				IsEnd = false;
				break;
			default:
				system("cls");
				printf_s("�߸��� �������� �Է��߽��ϴ�. �ٽ� �������ּ���\n\n");
				printf_s("����� �̸��� %s�Դϴ�. �����Ͻðڽ��ϱ�?\n", InputName);
				printf_s("a. ����\n");
				printf_s("b. ���Է�\n");
				break;
			}
		}

		if (true == IsEnd)
		{
			break;
		}
	}

	// �������ʱ��� ���⼭ �� ������� ����
	// ������ ������ FightZone�� ��� �ȴ�.
	// ���� ��� �������� 
	
	// new�� �� ����� �ϴ°ų�?
	// 8�Ⱑ
	UTown TownZone;
	TownZone.SetName("�ʺ�����");

	// 10�Ⱑ
	UFightZone FightZone;
	FightZone.SetName("�ʺ������");

	while (true)
	{
		TownZone.InPlayer(_Player);
	}



}