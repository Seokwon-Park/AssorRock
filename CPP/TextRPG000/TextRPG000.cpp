#include <iostream>
#include <conio.h>

const int LINECOUNT = 50;
const int NAMELEN = 20;
// Player
int PlayerAtt = 10;
int PlayerHp = 0;
char PlayerName[NAMELEN] = "NONE";

int MonsterAtt = 10;
int MonsterHp = 0;
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

void CreatePlayer(const char* const _Ptr, int _Att, int _Hp)
{
	StrCopy(PlayerName, NAMELEN, _Ptr);
	PlayerAtt = _Att;
	PlayerHp = _Hp;
}
void CreateMonster(const char* const _Ptr, int _Att, int _Hp)
{
	StrCopy(MonsterName, NAMELEN, _Ptr);
	MonsterAtt = _Att;
	MonsterHp = _Hp;
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

void Damage(const char* const _AttName, const char* const _DefName, int& _DefHp, int _Att)
{
	TakeDamage(_DefHp, _Att);
	DamageRender(_AttName, _DefName, _Att);
}

int main()
{
	CreatePlayer("TestPlayer", 10,100 );
	CreateMonster("Orc", 10,50 );


	while (true)
	{
		system("cls");
		char Input= ' ';

		PlayerStatusRender();
		MonsterStatusRender();

		Input = _getch();
		system("cls");
		TakeDamage(MonsterHp, PlayerAtt);
		PlayerStatusRender();
		MonsterStatusRender();
		DamageRender(PlayerName, MonsterName, PlayerAtt);
		
		Input = _getch();
		system("cls");
		TakeDamage(PlayerHp, MonsterAtt );
		PlayerStatusRender();
		MonsterStatusRender();
		DamageRender(PlayerName, MonsterName, PlayerAtt);
		DamageRender(MonsterName, PlayerName, MonsterAtt);
		Input = _getch();
	}



	return 0;
}

