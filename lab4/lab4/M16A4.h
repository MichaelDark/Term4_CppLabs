#pragma once
#include "GunAPI.h"
class M16A4 : public AutoRifle, public IBurst
{
public:
	M16A4()
		:AutoRifle() {}
	M16A4(LPCTSTR name, int bulletTotal, Bullet bulletInfo)
		: AutoRifle(name, bulletTotal, bulletInfo) {}
	M16A4(const Gun &gun) : AutoRifle(gun) {}

	int Shoot();
	int Shoot(int count);
	int ShootBurst();
	int Reload();

	~M16A4() {}
};

