#pragma once
#include "Group.h"

class Flow
{
	string _code;
	ulong _countGroups;
	ulong _maxCount;
	Group* _groups;
public:
	Flow();
	Flow(string code);

	bool AddGroup(Group student);
	bool RemoveGroup(string groupCode);
	bool RenameFlow(string newCode);
	bool HasGroup(string code);
	bool HasStudent(ulong id);

	ulong GroupsCount();
	ulong StudentsCount();
	bool IsEmpty();
	bool HasStudents();
	Group* Get(int index);
	string GetCode();

	void PrintInfo();
	void PrintGroups();
	void PrintStudents();

	~Flow();
private:
	void ExpandArray();
};

