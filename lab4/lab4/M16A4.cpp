#include "stdafx.h"
#include "GunAPI.h"

int M16A4::Shoot()
{
	return AutoRifle::Shoot(1);
}
int M16A4::Shoot(int count)
{
	return AutoRifle::Shoot(count);
}
int M16A4::ShootBurst()
{
	return AutoRifle::Shoot(3);
}
int M16A4::Reload()
{
	return AutoRifle::Reload();
}