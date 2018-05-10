#pragma once
#include "GunAPI.h"
class IBurst : public IAuto
{
protected:
	int ShootBurst() { return Shoot(3); }
};