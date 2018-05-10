#pragma once
#include "GunAPI.h"
class M416 : public AutoRifle
{
public:
	M416()
		:AutoRifle() {}
	M416(LPCTSTR name, int bulletTotal, Bullet bulletInfo)
		: AutoRifle(name, bulletTotal, bulletInfo) {}
	M416(const Gun &gun) : AutoRifle(gun) {}

	int Shoot();
	int Shoot(int count);
	int Reload();

	~M416() {}
};

