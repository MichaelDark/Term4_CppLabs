#include "stdafx.h"
#include "GunAPI.h"

int M416::Shoot()
{
	return AutoRifle::Shoot(1);
}
int M416::Shoot(int count)
{
	return AutoRifle::Shoot(count);
}
int M416::Reload()
{
	_tprintf(_T("God bless US"));
	return AutoRifle::Reload();
}