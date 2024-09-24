#include <iostream>

const int LINECOUNT = 50;
const int NAMELEN = 10;
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


int main()
{
	CreatePlayer("TestPlayer", 10,100 );
	CreateMonster("Orc", 10,50 );

	PlayerStatusRender();
	MonsterStatusRender();

	return 0;
}

