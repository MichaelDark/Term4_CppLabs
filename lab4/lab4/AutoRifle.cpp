#include "stdafx.h"
#include "GunAPI.h"

int AutoRifle::Shoot()
{
	return Shoot(1);
}
int AutoRifle::Shoot(int count)
{
	int result = GUN_ERROR;

	if (!HasBullets() || !_ready)
	{
		ActionReloadNeed();
	}
	else
	{
		for (int i = 0; i < count && _bulletRemaining != 0; i++)
		{
			_bulletRemaining--;
			ActionShoot();
			result = GUN_OK;
		}
	}
	_tprintf(_T("\r\n"));
	return result;
}
int AutoRifle::Reload()
{
	int result = GUN_ERROR;

	if (IsFull() && _ready)
	{
		ActionReloadNoNeed();
	}
	else
	{
		_ready = true;
		_bulletRemaining = _bulletTotal;
		ActionReload();
		result = GUN_OK;
	}
	_tprintf(_T("\r\n"));
	return result;
}