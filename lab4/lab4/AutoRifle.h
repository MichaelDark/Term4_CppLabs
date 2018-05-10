#pragma once
#include "Gun.h"
class AutoRifle : public Gun, public IAuto
{
public:
	AutoRifle()
		:Gun() {}
	AutoRifle(LPCTSTR name, int bulletTotal, Bullet bulletInfo)
		: Gun(name, bulletTotal, bulletInfo) {}
	AutoRifle(const Gun &gun) : Gun(gun) {}

	virtual int Shoot();
	virtual int Shoot(int count);
	virtual int Reload();

	~AutoRifle() {}
};

