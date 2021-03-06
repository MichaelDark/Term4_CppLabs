// lab4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GunAPI.h"

void PrintTitle(LPCTSTR caption);

int main()
{
	Gun* g1 = new M16A4(_T("M16A4 #1234"), 30, { _T("5.56"), 1000 });
	AutoRifle* g2 = new M416(_T("M416 #5678"), 30, { _T("5.56"), 900 });
	Gun* g3 = new Kar98K(_T("German Kar98K"), 5, { _T("5.56"), 1500 });
	Gun* g4 = new Gun(_T("Ordinary gun"), 20, { _T("5.56"), 1000 });

	PrintTitle(_T("M16A4 TEST"));

	g1->Shoot();
	g1->Reload();
	while (g1->HasBullets()) { ((M16A4*)g1)->ShootBurst(); }

	PrintTitle(_T("M416 TEST"));

	while (g2->HasBullets()) { g2->Shoot(); }
	g2->Shoot();
	g2->Reload();
	while (g2->HasBullets()) { g2->Shoot(); }
	g2->Reload();
	g2->Shoot(25);
	g2->Shoot(25);
	g2->Reload();
	g2->Shoot(29);
	g2->Shoot();
	g2->Shoot();

	PrintTitle(_T("Kar98K TEST"));

	g3->Reload();
	g3->Shoot();
	for(int i = 0; i < 4; i++)
	{
		g3->Shoot();
		g3->Reload();
	}



	system("pause");
	delete g1;
	delete g2;
	delete g3;
    return 0;
}

void PrintTitle(LPCTSTR caption)
{
	_tprintf(_T("========================================\r\n"));
	_tprintf(_T("=====%10s=====\r\n"), caption);
	_tprintf(_T("========================================\r\n"));
}
