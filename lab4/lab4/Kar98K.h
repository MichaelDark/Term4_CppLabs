#pragma once
#include "GunAPI.h"
class Kar98K : public Gun
{
public:
	Kar98K()
		:Gun() {}
	Kar98K(LPCTSTR name, int bulletTotal, Bullet bulletInfo)
		: Gun(name, bulletTotal, bulletInfo) {}
	Kar98K(const Gun &gun) : Gun(gun) {}

	int Shoot();
	int Reload();

	~Kar98K() {}
};

