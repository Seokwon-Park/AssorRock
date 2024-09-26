#include <iostream>
#include <conio.h>

const int NAMELEN = 10;
const int LINECOUNT = 50;

class StatusUnit
{
public:
	StatusUnit()
		:Name("NoName"), Hp(100), MinAtt(10), MaxAtt(20), Speed(10)
	{
		std::cout << "Call default StatusUnit Constructor.\n";
	}
	StatusUnit(const char* const _name, int _hp, int _minAtt, int _maxAtt, int _speed)
		:Hp(_hp), MinAtt(_minAtt), MaxAtt(_maxAtt), Speed(_speed)
	{
		strcpy_s(Name, _name);
	}

	void StatusRender()
	{
		int count = printf_s("%s Status", Name);

		for (int i = 0; i < LINECOUNT - count; i += 1)
		{
			printf_s("-");
		}
		printf_s("\n");
		printf_s("최소 공격력 : %d\n", MinAtt);
		printf_s("최대 공격력 : %d\n", MaxAtt);
		printf_s("체력 : %d\n", Hp);

		for (int i = 0; i < LINECOUNT; i += 1)
		{
			printf_s("-");
		}
		printf_s("\n");
	}
protected:
	char Name[NAMELEN] = "NONE";
	int Hp = 100;
	int MinAtt = 10;
	int MaxAtt = 20;
	int Speed = 10;
	int Charm = 0;
};

class FightUnit : public StatusUnit
{
public:
	FightUnit()
	{
		std::cout << "Call default FightUnit Constructor.\n";
	}
	FightUnit(const char* const _name, int _hp, int _minAtt, int _maxAtt, int _speed)
		:StatusUnit(_name, _hp, _minAtt, _maxAtt, _speed) {}

	// MinMax
	int GetDamage() const
	{
		return MinAtt + rand() % (MaxAtt - MinAtt + 1);
	}

	void TakeDamage(const FightUnit& _AttUnit)
	{
		int Damage = _AttUnit.GetDamage();
		Hp -= Damage;
		LastDamage = Damage;
	}

	void DamageRender(const FightUnit& _AttUnit)const
	{
		printf_s("%s 가 %s를 공격해서 %d의 데미지를 입혔습니다.\n", _AttUnit.Name, Name, LastDamage);
	}

	const char* GetName() const
	{
		return Name;
	}

protected:
	int LastDamage; // 마지막으로 입은 피해량

private:
};

class Player : public FightUnit
{
public:
	Player()
	{
		std::cout << "Call default Player Constructor.\n";
		strcpy_s(Name, "Player");
	}
	Player(const char* const _name, int _hp, int _minAtt, int _maxAtt, int _speed)
		:FightUnit(_name, _hp, _minAtt, _maxAtt, _speed) {}
};

class Monster : public FightUnit
{
public:
	Monster()
	{
		std::cout << "Call default Monster Constructor.\n";
		strcpy_s(Name, "Monster");
	}
	Monster(const char* const _name, int _hp, int _minAtt, int _maxAtt, int _speed)
		:FightUnit(_name, _hp, _minAtt, _maxAtt, _speed) {}
};

int main()
{
	srand(time(0));
	Player NewPlayer = Player("MyPlayer", 100, 20, 30, 10);
	Monster NewMonster = Monster("Enemy", 50, 10, 20, 5);

	char ch = 0;
	while (1)
	{
		
		system("cls");
		NewPlayer.StatusRender();
		NewMonster.StatusRender();

		ch = _getch();
		system("cls");
		NewMonster.TakeDamage(NewPlayer);
		NewPlayer.StatusRender();
		NewMonster.StatusRender();
		NewMonster.DamageRender(NewPlayer);
		ch = _getch();

	}

}
