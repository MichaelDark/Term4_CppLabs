#include "stdafx.h"
#include "GunAPI.h"

Gun::Gun()
{
	_name = new TCHAR[4];
	_tcscpy(_name, _T("Gun"));
	_bulletType = { _T(""), 0 };
	_bulletTotal = 0;
	_bulletRemaining = 0;
	_ready = false;
}
Gun::Gun(LPCTSTR name, int bulletTotal, Bullet bulletInfo)
{
	_name = new TCHAR[_tcslen(name)];
	_tcscpy(_name, name);
	_bulletType = bulletInfo;
	_bulletTotal = bulletTotal;
	_bulletRemaining = 0;
	_ready = false;
}
Gun::Gun(const Gun &obj)
{
	_name = new TCHAR[_tcslen(obj._name)];
	_tcscpy(_name, obj._name);
	_bulletType = obj._bulletType;
	_bulletTotal = obj._bulletTotal;
	_bulletRemaining = obj._bulletRemaining;
	_ready = obj._ready;
}

Gun& Gun::operator=(const Gun &gun) {
	if (this != &gun) 
	{
		_name = new TCHAR[_tcslen(gun._name)];
		_tcscpy(_name, gun._name);
		_bulletType = gun._bulletType;
		_bulletTotal = gun._bulletTotal;
		_bulletRemaining = gun._bulletRemaining;
		_ready = gun._ready;
	}
	return *this;
}

int Gun::Shoot()
{
	int result = GUN_ERROR;

	if (!HasBullets() || !_ready)
	{
		ActionReloadNeed();
	}
	else
	{
		_ready = false;
		_bulletRemaining--;
		ActionShoot();
		result = GUN_OK;
	}
	_tprintf(_T("\r\n"));
	return result;
}
int Gun::Reload()
{
	int result = GUN_ERROR;

	if (IsFull() && _ready)
	{
		ActionReloadNoNeed();
	}
	else
	{
		_ready = true;
		if (!HasBullets())
		{
			_bulletRemaining = _bulletTotal;
		}
		ActionReload();
		result = GUN_OK;
	}
	_tprintf(_T("\r\n"));
	return result;
}

void Gun::ActionShoot()
{
	_tprintf(_T("%s BDISH %d\r\n"), _name, (_bulletTotal - _bulletRemaining));
}
void Gun::ActionReload()
{
	_tprintf(_T("%s RELOADED, %d\r\n"), _name, _bulletRemaining);
}
void Gun::ActionReloadNeed()
{
	_tprintf(_T("%s NEEDS TO BE RELOADED\r\n"), _name);
}
void Gun::ActionReloadNoNeed()
{
	_tprintf(_T("%s DOESNT NEED TO BE RELOADED\r\n"), _name);
}

bool Gun::Ready()
{
	return _ready;
}
bool Gun::IsFull()
{
	return _bulletRemaining == _bulletTotal;
}
bool Gun::HasBullets()
{
	return _bulletRemaining > 0;
}
int Gun::GetBulletsTotal()
{
	return _bulletTotal;
}
int Gun::GetBulletsRemaining()
{
	return _bulletRemaining;
}
Bullet Gun::GetCaliber()
{
	return _bulletType;
}