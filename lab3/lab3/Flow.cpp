#include "stdafx.h"
#include "Flow.h"

Flow::Flow()
{
	_code = (char*)"";

	_countGroups = 0;
	_maxCount = 30;
	_groups = new Group[_maxCount];
}
Flow::Flow(char* code)
{
	_code = new char[strlen(code) + 1];
	strcpy(_code, code);

	_countGroups = 0;
	_maxCount = 30;
	_groups = new Group[_maxCount];
}
Flow::Flow(const Flow &obj)
{
	Flow newFlow(_code);
	for (int i = 0; i < _countGroups; i++)
	{
		newFlow.AddGroup(_groups[i]);
	}
}

bool Flow::AddGroup(Group group)
{
	if (_countGroups + 1 >= _maxCount)
		ExpandArray();

	_groups[_countGroups] = group;
	_countGroups++;
	return true;
}
bool Flow::HasGroup(char* groupCode)
{
	for (int i = 0; i < _countGroups; i++)
	{
		if (_groups[i].GetCode() == groupCode)
		{
			return true;
		}
	}
	return false;
}
bool Flow::HasStudent(ulong id)
{
	for (int i = 0; i < _countGroups; i++)
	{
		if (_groups[i].HasStudent(id))
		{
			return true;
		}
	}
	return false;
}
bool Flow::RemoveGroup(char* groupCode)
{
	if (IsEmpty())
		return false;

	int index = -1;

	for (int i = 0; i < _countGroups; i++)
	{
		if (_groups[i].GetCode() == groupCode)
		{
			index = i;
			break;
		}
	}

	if (index != -1)
	{
		for (int i = index; i < _countGroups - 1; i++)
		{
			_groups[i] = _groups[i + 1];
		}
		_countGroups--;
		return true;
	}
	else
	{
		return false;
	}
}
bool Flow::RenameFlow(char* newCode)
{
	if (newCode == "")
		return false;

	_code = new char[strlen(newCode) + 1];
	strcpy(_code, newCode);
	return true;
}

ulong Flow::GroupsCount()
{
	return _countGroups;
}
ulong Flow::StudentsCount()
{
	ulong count = 0;

	for (int i = 0; i < _countGroups; i++)
	{
		count += _groups[i].StudentsCount();
	}
	return count;
}
bool Flow::IsEmpty()
{
	return _countGroups == 0;
}
bool Flow::HasStudents()
{
	ulong groupsCount = GroupsCount();
	for (int i = 0; groupsCount; i++)
	{
		if (_groups[i].StudentsCount() > 0)
		{
			return true;
		}
	}
	return false;
}
Group* Flow::Get(int index)
{
	return &_groups[index];
}
char* Flow::GetCode()
{
	return _code;
}

void Flow::PrintInfo()
{
	cout << "== Flow Info " << endl;
	cout << "Code    : " << _code << endl;
	cout << "Groups  : " << _countGroups << endl;
	cout << "Students: " << StudentsCount() << endl;
	cout << endl;
}
void Flow::PrintGroups()
{
	if (IsEmpty())
	{
		cout << "Flow has no groups";
		return;
	}

	cout << "== Flow: " << _code << endl;
	cout << "num:    count,    name" << endl;
	for (int i = 0; i < _countGroups; i++)
	{
		Group* currGroup = Get(i);
		cout << setw(3) << i + 1 << ": " 
			<< setw(8) << currGroup->StudentsCount() << ", " 
			<< currGroup->GetCode() << endl;
	}
	cout << endl;
}
void Flow::PrintStudents()
{
	if (IsEmpty())
	{
		cout << "Flow has no groups";
		return;
	}
	if (!HasStudents())
	{
		cout << "Flow has no members";
		return;
	}
	ulong totalCount = 1;

	cout << "== Flow: " << _code << endl;
	cout << "num:       id,    name" << endl;
	for (int i = 0; i < _countGroups; i++)
	{
		Group* currGroup = Get(i);
		ulong studentCount = currGroup->StudentsCount();
		for (int j = 0; j < studentCount; j++)
		{
			Student* currStudent = currGroup->Get(j);
			cout << setw(3) << totalCount << ": " << setw(8) << currStudent->id << ", " << currStudent->name << endl;
			totalCount++;
		}
	}
	cout << endl;
}

Flow::~Flow()
{
	_code = nullptr;
	delete[] _groups;
}

void Flow::ExpandArray()
{
	int newSize = _countGroups * 2;
	Group* temp = new Group[newSize];
	for (int i = 0; i < _countGroups; i++)
	{
		temp[i] = _groups[i];
	}
	_groups = temp;
	_maxCount = newSize;
	delete[] temp;
}