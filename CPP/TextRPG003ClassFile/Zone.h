#pragma once
#include "StatusUnit.h"
#include "Player.h"


// �������� ������ ū�� ���ϴ�.
class UZone : public UStatusUnit
{
public:
	void InMsgPrint();
	virtual int InPlayer(class UPlayer& _Player);

};