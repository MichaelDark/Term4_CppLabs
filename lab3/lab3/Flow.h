#pragma once
#include "Group.h"

class Flow
{
	char* _code;
	ulong _countGroups;
	ulong _maxCount;
	Group* _groups;
public:
	Flow();
	Flow(char* code);
	Flow(const Flow &obj);

	bool AddGroup(Group student);
	bool RemoveGroup(char* groupCode);
	bool RenameFlow(char* newCode);
	bool HasGroup(char* code);
	bool HasStudent(ulong id);

	ulong GroupsCount();
	ulong StudentsCount();
	bool IsEmpty();
	bool HasStudents();
	Group* Get(int index);
	char* GetCode();

	void PrintInfo();
	void PrintGroups();
	void PrintStudents();

	~Flow();
private:
	void ExpandArray();
};

