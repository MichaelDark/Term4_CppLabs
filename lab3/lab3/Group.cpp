#include "stdafx.h"
#include "Group.h"

Group::Group()
{
	_code = (char*)"";

	_countStudents = 0;
	_maxCount = 30;
	_students = new Student[_maxCount];
}
Group::Group(char* code)
{
	_code = new char[strlen(code) + 1];
	strcpy(_code, code);

	_countStudents = 0;
	_maxCount = 30;
	_students = new Student[_maxCount];
}
Group::Group(char* code, Student* students, ulong count)
{
	_code = new char[strlen(code) + 1];
	strcpy(_code, code);

	_countStudents = count;
	_maxCount = count;
	_students = students;
}
Group::Group(const Group &obj)
{
	_code = new char[strlen(obj._code) + 1];
	strcpy(_code, obj._code);

	_countStudents = 0;
	_maxCount = 30;
	_students = new Student[_maxCount];

	for (int i = 0; i < obj._countStudents; i++)
	{
		AddStudent(obj._students[i]);
	}
}

Group& Group::operator=(Group &group) //перегрузка оператора присваивания
{
	_code = new char[strlen(group._code) + 1];
	strcpy(_code, group._code);

	_countStudents = 0;
	_maxCount = 30;
	_students = new Student[_maxCount];

	for (int i = 0; i < group._countStudents; i++)
	{
		AddStudent(group._students[i]);
	}

	return *this;
}

bool Group::AddStudent(Student student)
{
	if (_countStudents + 1 >= _maxCount)
		ExpandArray();

	_students[_countStudents] = student;
	_countStudents++;
	return true;
}
bool Group::HasStudent(ulong id)
{
	for (int i = 0; i < _countStudents; i++)
	{
		if (_students[i].id == id)
		{
			return true;
		}
	}
	return false;
}
bool Group::RemoveStudent(ulong id)
{
	if (IsEmpty())
		return false;

	int index = -1;

	for (int i = 0; i < _countStudents; i++)
	{
		if (_students[i].id == id)
		{
			index = i;
			break;
		}
	}

	if (index != -1)
	{
		for (int i = index; i < _countStudents - 1; i++)
		{
			_students[i] = _students[i + 1];
		}
		_countStudents--;
		return true;
	}
	else
	{
		return false;
	}
}
bool Group::RenameGroup(char* newCode)
{
	if (newCode == "")
		return false;

	_code = new char[strlen(newCode) + 1];
	strcpy(_code, newCode);
	return true;
}

bool Group::IsEmpty()
{
	return _countStudents == 0;
}
ulong Group::StudentsCount()
{
	return _countStudents;
}
Student* Group::Get(int index)
{
	return (_students + index);
}
char* Group::GetCode()
{
	return _code;
}


void Group::PrintInfo()
{
	cout << "== Group Info " << endl;
	cout << "Code    : " << _code << endl;
	cout << "Students: " << _countStudents << endl;
	cout << endl;
}
void Group::PrintStudents()
{
	if (IsEmpty())
	{
		cout << "Group has no members";
		return;
	}

	cout << "== Group list: " << _code << endl;
	cout << "num:       id,    name" << endl;
	for (int i = 0; i < _countStudents; i++)
	{
		cout << setw(3) << i + 1 << ": " 
			<< setw(8) << _students[i].id << ", " 
			<< _students[i].name << endl;
	}
	cout << endl;
}

Group::~Group()
{
	_code = nullptr;
	delete[] _students;
}

void Group::ExpandArray()
{
	int newSize = _countStudents * 2;
	Student* temp = new Student[newSize];
	for (int i = 0; i < _countStudents; i++)
	{
		temp[i] = _students[i];
	}
	_students = temp;
	_maxCount = newSize;
	delete[] temp;
}