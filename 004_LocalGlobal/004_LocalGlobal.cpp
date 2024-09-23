#include <iostream>

// 변수를 선언했다. 
// 선언하기 전까지는 아직 PlayerHp는 존재하지 않는 것이다.
int PlayerHp;
int PlayerDamage;

int MonsterHp;
int MonsterDamage;

// = 100

void CreatePlayer()
{
    // 플레이러를 만들었다.
    PlayerHp = 100;
    PlayerDamage = 10;

    // 지역
    // 그보다 위에서는 사용할수 없다.
}

void CreateMonster()
{
    // = 100
    MonsterHp = 100;
    MonsterDamage = 10;
}


int main()
{
    // 코딩스타일 적으로 
    // 가독성을 좋게 짠다고 하는데.
    CreatePlayer();



}
