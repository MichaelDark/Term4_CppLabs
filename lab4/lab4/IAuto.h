#pragma once
#include "GunAPI.h"
class IAuto
{
protected:
	virtual int Shoot(int count) = 0;
};