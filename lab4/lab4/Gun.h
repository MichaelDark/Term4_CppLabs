#pragma once
#include "GunAPI.h"
enum
{
	GUN_OK = 0,
	GUN_ERROR = 1
};
struct Bullet
{
	LPCTSTR Caliber;
	int Power;
};
class Gun
{
protected:
	TCHAR* _name;
	Bullet _bulletType;
	int _bulletTotal;
	int _bulletRemaining;
	bool _ready;
public:
	Gun();
	Gun(LPCTSTR name, int bulletTotal, Bullet bulletInfo);
	Gun(const Gun &);

	Gun& operator=(const Gun &gun);

	virtual int Shoot();
	virtual int Reload();

	void ActionShoot();
	void ActionReload();
	void ActionReloadNeed();
	void ActionReloadNoNeed();

	bool Ready();
	bool IsFull();
	bool HasBullets();
	int GetBulletsTotal();
	int GetBulletsRemaining();
	Bullet GetCaliber();

	virtual ~Gun() {}
};
