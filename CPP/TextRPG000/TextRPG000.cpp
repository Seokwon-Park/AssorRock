#include <iostream>
#include <conio.h>
#include <random>

const int LINECOUNT = 50;
const int NAMELEN = 20;
// Player
int PlayerAtt = 10;
int PlayerHp = 0;
int PlayerSpeed = 10;
char PlayerName[NAMELEN] = "NONE";

int MonsterAtt = 10;
int MonsterHp = 0;
int MonsterSpeed = 10;
char MonsterName[NAMELEN] = "NONE";

void StrCopy(char* _Arr, int _BufferSize, const char* const _Name)
{
	for (int i = 0; i < _BufferSize; i++)
	{
		_Arr[i] = 0;
	}

	int Size = strlen(_Name);
	for (int i = 0; i < Size; i++)
	{
		_Arr[i] = _Name[i];
	}
}

void CreatePlayer(const char* const _Ptr, int _Att, int _Hp, int _Speed)
{
	StrCopy(PlayerName, NAMELEN, _Ptr);
	PlayerAtt = _Att;
	PlayerHp = _Hp;
	PlayerSpeed = _Speed;
}
void CreateMonster(const char* const _Ptr, int _Att, int _Hp, int _Speed)
{
	StrCopy(MonsterName, NAMELEN, _Ptr);
	MonsterAtt = _Att;
	MonsterHp = _Hp;
	PlayerSpeed = _Speed;
}

void StatusRender(const char* _Name, int _Att, int _Hp)
{
	int Size = printf_s("%s status ", _Name);
	for (int i = 0; i < LINECOUNT - Size; i++)
	{
		printf_s("-");
	}
	printf_s("\n");
	printf_s("공격력 : %d\n", _Att);
	printf_s("체력 : %d\n", _Hp);

	for (int i = 0; i < LINECOUNT; i += 1)
	{
		printf_s("-");
	}
	printf_s("\n");
}

void PlayerStatusRender()
{
	StatusRender(PlayerName, PlayerAtt, PlayerHp);
}

void MonsterStatusRender()
{
	StatusRender(MonsterName, MonsterAtt, MonsterHp);
}

void DamageRender(const char* const _AttName, const char* const _DefName, int _Att)
{
	printf_s("%s가 %s를 공격해서 %d의 데미지를 입혔습니다.\n", _AttName, _DefName, _Att);
}

void TakeDamage(int& _DefHp, int _Att)
{
	_DefHp -= _Att;
}

void SpeedCheckRender(const char* const _Name)
{
	printf_s("%s 의 선공입니다\n", _Name);
}

void Damage(const char* const _AttName, const char* const _DefName, int& _DefHp, int _Att)
{
	TakeDamage(_DefHp, _Att);
	DamageRender(_AttName, _DefName, _Att);
}

int GenSpeed(std::mt19937& gen, std::uniform_int_distribution<int>& dis)
{
	return dis(gen);
}

int main()
{
	CreatePlayer("TestPlayer", 10, 100, 20);
	CreateMonster("Orc", 10, 50, 10);

	srand(time(0));
	std::mt19937 gen;
	std::uniform_int_distribution<int> player(0, PlayerSpeed);
	std::uniform_int_distribution<int> monster(0, MonsterSpeed);


	while (true)
	{
		system("cls");
		char Input = ' ';

		PlayerStatusRender();
		MonsterStatusRender();

		//int RandomPlayerSpeed = rand() % PlayerSpeed;
		//int RandomMonsterSpeed = rand() % MonsterSpeed;
		int RandomPlayerSpeed = GenSpeed(gen, player);
		int RandomMonsterSpeed = GenSpeed(gen, monster);
		bool isPlayerFirst = RandomPlayerSpeed > RandomMonsterSpeed;

		if (isPlayerFirst)
		{
			SpeedCheckRender(PlayerName);
		}
		else
		{
			SpeedCheckRender(MonsterName);
		}
		Input = _getch();
		system("cls");
		if (isPlayerFirst) // 플레이어 선공
		{
			TakeDamage(MonsterHp, PlayerAtt);
		}
		else
		{
			TakeDamage(PlayerHp, MonsterAtt);
		}
		PlayerStatusRender();
		MonsterStatusRender();
		if (isPlayerFirst)
		{
			SpeedCheckRender(PlayerName);
			DamageRender(PlayerName, MonsterName, PlayerAtt);
		}
		else
		{
			SpeedCheckRender(MonsterName);
			DamageRender(MonsterName, PlayerName, MonsterAtt);
		}

		// 공격 턴 교체
		Input = _getch();
		system("cls");
		if (isPlayerFirst) // 플레이어가 선공이었다면 몬스터 공격차례
		{
			TakeDamage(PlayerHp, MonsterAtt);
		}
		else
		{
			TakeDamage(MonsterHp, PlayerAtt);
		}
		PlayerStatusRender();
		MonsterStatusRender();
		if (isPlayerFirst)
		{
			SpeedCheckRender(PlayerName);
			DamageRender(PlayerName, MonsterName, PlayerAtt);
			DamageRender(MonsterName, PlayerName, MonsterAtt);
		}
		else
		{
			SpeedCheckRender(MonsterName);
			DamageRender(MonsterName, PlayerName, MonsterAtt);
			DamageRender(PlayerName, MonsterName, PlayerAtt);
		}

		Input = _getch();
	}



	return 0;
}

