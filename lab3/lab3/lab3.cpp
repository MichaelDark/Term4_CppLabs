#include "stdafx.h"
#include "Flow.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	Student people[] = {
	{ 1, (char*)"Понедельников Геннадий Михайлович" },
	{ 2, (char*)"Белоус Полина" },
	{ 3, (char*)"Шевяков Вячеслав Игоревич" },
	{ 4, (char*)"Цыбульник Богдан Валентинович" },
	{ 5, (char*)"Темнохуд Михаил Игоревич" },
	{ 6, (char*)"Валуйский Владислав Евгеньевич" },
	{ 7, (char*)"Рублёв Андроид" },
	{ 8, (char*)"Губарь Сергей" }
	};

	char groupname[100];
	cin >> groupname;

	Group group1((char*)groupname);
	group1.AddStudent(people[0]);
	group1.AddStudent(people[1]);
	group1.PrintStudents();

	group1.RenameGroup((char*)"ПЗПИ-16-1");
	group1.PrintStudents();

	Group group2((char*)"ПЗПИ-16-2");
	group2.AddStudent(people[2]);
	group2.AddStudent(people[3]);
	group2.AddStudent(people[4]);
	group2.AddStudent(people[5]);
	group2.PrintStudents();

	group2.RemoveStudent(4); 
	group2.PrintStudents();

	Group group3((char*)"ПЗПИ-16-3");
	group3.AddStudent(people[6]);
	group3.AddStudent(people[7]);
	group3.PrintStudents();
	
	Flow flow((char*)"ПЗПИ");
	flow.AddGroup(group1);
	flow.AddGroup(group2);
	flow.AddGroup(group3);

	flow.Get(0)->RenameGroup((char*)"PZPI-16-1");

	flow.PrintInfo();
	flow.PrintGroups();
	flow.PrintStudents();

	Group* firstGroup = flow.Get(1);
	firstGroup->RemoveStudent(6);
	flow.PrintInfo();
	flow.PrintGroups();
	flow.PrintStudents();
	
	system("pause");

    return 0;
}

