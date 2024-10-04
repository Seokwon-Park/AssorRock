#include "World.h"
#include "FightZone.h"
#include "Town.h"
#include "Player.h"
#include <BaseSystem/EngineDebug.h>
#include <BaseSystem/EngineFile.h>

// #include "EngineFile.h"

// #include "..\BaseSystem\EngineFile.h"
// �������� ����� �ƴմϴ�.

// #include < <= �����ϴ� �ܺΰ�δ� ũ�� 2���� ����� ������ �޴´�.


#include <conio.h>



void UWorld::PlayerNameSelect(class UPlayer& _Player)
{
	// C:\\

	char InputName[100] = { 0, };

	bool IsNameInput = true;

	while (true)
	{
		if (true == IsNameInput)
		{
			system("cls");
			std::cout << "�̸��� �����ּ���" << std::endl;
			std::cin >> InputName;
		}

		system("cls");
		printf_s("����� �̸��� %s�Դϴ�. �����Ͻðڽ��ϱ�?\n", InputName);
		printf_s("a. ����\n");
		printf_s("b. ���Է�\n");
		int Select = _getch();

		bool IsEnd = true;
		switch (Select)
		{
		case 'a':
		case 'A':
			IsEnd = true;
			break;
		case 'b':
		case 'B':
			IsEnd = false;
			IsNameInput = true;
			break;
		default:
			IsEnd = false;
			IsNameInput = false;
			printf_s("�߸��� �����Դϴ�. �ٽ� �������ּ���\n");
			_getch();
			break;
		}

		if (true == IsEnd)
		{
			break;
		}
	}

	// ���� ����

	_Player.SetName(InputName);
}

void UWorld::PlayerZonePlay(class UPlayer& _Player)
{
	UTown TownZone0;
	TownZone0.SetName("�ʺ�����");

	UTown TownZone1;
	TownZone1.SetName("�߱޸���");

	UFightZone FightZone;
	FightZone.SetName("�ʺ������");

	UZone* CurrentZone = &TownZone0;

	while (true)
	{
		int Result = CurrentZone->InPlayer(_Player);
		if (Result == TownIndex::chobo)
		{
			CurrentZone = &TownZone0;
		}
		else if (Result == TownIndex::middle)
		{
			CurrentZone = &TownZone1;
		}
		else if (Result == TownIndex::fight)
		{
			CurrentZone = &FightZone;
		}
	}
}

void UWorld::InPlayer(class UPlayer& _Player)
{
	// �ܺα�� ����� �ְ� CPP�� ����. 
	UEngineFile File;
	File.SetPath("SaveFile.Dat");

	// ������ ������
	if (false == File.IsExits())
	{
		File.FileOpen("wb");

		// �̸� ���ϰ� ���Դ�.
		PlayerNameSelect(_Player);
		const char* Name = _Player.GetName();

		// ���ڿ��� �����Ҷ��� ������ �ִ�.
		// �ʹݿ��� �������� �ִ�.
		// �����Ҷ� ���� ���� ����� ũ�Ⱑ �����Ǿ� �ִ� ���̴�.
		File.Write(Name, NAMELEN);
	}
	else
	{
		File.FileOpen("rb");

		char Arr[100] = {};
		File.Read(Arr, NAMELEN);
		_Player.SetName(Arr);
	}

	PlayerZonePlay(_Player);
}