#include "stdafx.h"
#include "Flow.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	Student people[] = {
	{ 1, "Понедельников Геннадий Михайлович" },
	{ 2, "Белоус Полина" },
	{ 3, "Шевяков Вячеслав Игоревич" },
	{ 4, "Цыбульник Богдан Валентинович" },
	{ 5, "Темнохуд Михаил Игоревич" },
	{ 6, "Валуйский Владислав Евгеньевич" },
	{ 7, "Рублёв Андроид" },
	{ 8, "Губарь Сергей" }
	};

	Group group1("ПЗПИ-16-0");
	group1.AddStudent(people[0]);
	group1.AddStudent(people[1]);
	group1.PrintStudents();

	group1.RenameGroup("ПЗПИ-16-1");
	group1.PrintStudents();

	Group group2("ПЗПИ-16-2");
	group2.AddStudent(people[2]);
	group2.AddStudent(people[3]);
	group2.AddStudent(people[4]);
	group2.AddStudent(people[5]);
	group2.PrintStudents();

	group2.RemoveStudent(4); 
	group2.PrintStudents();

	Group group3("ПЗПИ-16-3");
	group3.AddStudent(people[6]);
	group3.AddStudent(people[7]);
	group3.PrintStudents();
	
	Flow flow("ПЗПИ");
	flow.AddGroup(group1);
	flow.AddGroup(group2);
	flow.AddGroup(group3);

	flow.Get(0)->RenameGroup("PZPI-16-1");

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

