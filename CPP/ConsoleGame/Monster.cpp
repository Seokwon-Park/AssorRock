#include "Monster.h"
#include "Renderer.h"
#include "Player.h"


void Monster::BeginPlay()
{
	Super::BeginPlay();

	Renderer* Render = CreateDefaultSubObject();
	Render->RenderImage.Create({ 1, 1 }, 'M');
}

void Monster::Tick()
{
	const ActorVector& bullets = Player::GetPlayer()->GetBulletVector();

	for (int i = 0; i < bullets.size(); i++)
	{

	}
	// ���� ���
	// Monster::Tick();

	// 1. ��� �Ѿ��� �����´�.
	// 2. ��� �Ѿ� �� �ڽ��� ��ġ�� ���ؾ� �Ѵ�.
	//    ������ ����� ���� �����ָ� �հ����� ���� �־���ϴ���?

	// 1-1. ���������� ���� §��. 
	//      ������ ���� �����ϴ� ����� �����. ��ų�Ŵ��� ����� ����
	//      Ŭ���̾�Ʈ ���α׷��Ӱ� �̹���� ��ȣ�մϴ�.
	//      ������ �����ϴ� ����� �˾Ƴ��°� �� ����.
	//      ������ ����� ���� ������ ������� ������ ������� �ʴ°� ����.
	//      
	// 1-2. ������ ����� �̿��Ѵ�. ������ ����� ��κ� ������.
	//      �������̰� �����ϰ� ¥���� �ֱ� ������ 
	//      ������ ���忡�� Player Monster Bullet�� �� => AActor�� ���̴�.
	//      �ڷᱸ�� �ϳ����� �����ϰ� 100
	//      �������� �����ϴ� FindObject�� Find ���� ��ɵ��� ��κ� �����ϴ� ��ɵ�.
	//      Find(const char*) <= ������ ���ڿ� �񱳶� 2��� ������.


}


