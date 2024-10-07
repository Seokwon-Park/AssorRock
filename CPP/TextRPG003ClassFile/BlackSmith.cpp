#include "BlackSmith.h"
#include "Player.h"
#include <BaseSystem/EngineDebug.h>
#include <conio.h>
#include <random>




void BlackSmith::InPlayer(class UPlayer& _Player/*, int& Result*/)
{
	
	if (nullptr == ParentZone)
	{
		MSGASSERT("�θ����� ���õ��� �ʾҽ��ϴ�");
		return;
	}


	_Player.SetGold(1000000);

	srand(static_cast<unsigned int>(time(nullptr)));

	while (true)
	{
		system("cls");
		std::cout << ParentZone->GetName() << "�� ���尣�� �����߽��ϴ�\n";
		_Player.StatusRender();
		std::cout << "1. ��ȭ\n";
		std::cout << "2. ������\n";
		int Select = _getch();
		switch (Select)
		{
		case '1':
			TryUpgrade(_Player);
			_getch();
			break;
		case '2':
			return;
		default:
			break;
		}
	}
}

void BlackSmith::TryUpgrade(class UPlayer& _Player)
{
	system("cls");
	// Ȯ���� ���δ� 2���� 1
	// 1���� �𿩾� �Ѵ�. �÷��̾��� ��ȭ �ܰ� * 100
	// ���� ���� 5���� �����ϰ� �ִ�. �׷��� 500���� �￩�� �Ѵ�.
	// 1~5������ ���а� ����Ȯ���� ������.
	// �ٿ������ �ʴ´�.
	// 6~10������ �����ϸ� 1�� �ٿ�ȴ�.
	// 10~15�� 0���� �����ϸ� 0���� ��������.
	// 15�� �̻��̸� ��ȭ�� ���ϰ� �ؾ����Ѵ�.
	int CurGold = _Player.GetGold();
	int CurUpgrade = _Player.GetEquipUpgrade();
	int UpgradeCost = (CurUpgrade+1) * 100;
	
	std::cout << "======================= �� ȭ =======================\n\n";


	std::cout << UpgradeCost << "��带 ����Ͽ� +" << CurUpgrade << " -> +" << CurUpgrade+1 << "�� ��ȭ�� �õ��մϴ�...\n";
	
	//���� ������ ���
	if (CurGold < UpgradeCost)
	{
		std::cout << "��ȭ ����� �����մϴ�.\n";
		return;
	}

	//15�� �̻��� ���
	if (15 == CurUpgrade)
	{
		std::cout << "�� �̻� ��ȭ�� �� �����ϴ�.\n";
		return;
	}
	_Player.SetGold(CurGold - UpgradeCost);
	// ��ȭ����

	// int Result = 1; 
	int Result = rand() % 2;
	int UpgradeResult = CurUpgrade;
	//50%
	if (0 < Result ) // 0 : ���� 1 : ���� 
	{
		std::cout << "��ȭ�� �����߽��ϴ�!!!\n\n";
		UpgradeResult = CurUpgrade + 1;
		_Player.SetEquipUpgrade(UpgradeResult);
		std::cout << "��ȭ ��ġ�� 1 �����߽��ϴ�.\n";
	}
	else
	{
		std::cout << "��ȭ�� �����߽��ϴ�...\n\n";
		if (10 <= CurUpgrade) // 10->11 ���ʹ� �����ϸ� 0
		{
			UpgradeResult = 0;
			_Player.SetEquipUpgrade(UpgradeResult);
			std::cout << "��ȭ ��ġ�� 0���� �ʱ�ȭ �Ǿ����ϴ�. �Ф�\n";
		}
		else if (5 <= CurUpgrade) // 10���� �۰� 5->6���ʹ� �����ϸ� 1��
		{
			UpgradeResult = CurUpgrade -1 ;
			_Player.SetEquipUpgrade(CurUpgrade - 1);
			std::cout << "��ȭ ��ġ�� 1 �����߽��ϴ�.\n";
			
		}
		
	}

	std::cout << "��ȭ ��� : +" << CurUpgrade << " -> +" << UpgradeResult << '\n';
	std::cout << "��� : " << CurGold << " -> " << _Player.GetGold() << '\n';

	std::cout << '\n';
	_Player.StatusRender();

	std::cout << "�ƹ�Ű�� ������ ��ȭ ȭ������ ���ư��ϴ�...\n";
}