#pragma once
#define STUDENT_NULL {-1, "null"}

struct Student
{
	ulong id;
	char* name;
};

class Group
{
	char* _code;
	ulong _countStudents;
	ulong _maxCount;
	Student* _students;
public:
	Group();
	Group(char* code);
	Group(char* code, Student* students, ulong count);
	Group(const Group &obj);

	Group& operator=(Group &group);

	bool AddStudent(Student student);
	bool HasStudent(ulong id);
	bool RemoveStudent(ulong id);
	bool RenameGroup(char* newCode);

	bool IsEmpty();
	ulong StudentsCount();
	Student* Get(int index);
	char* GetCode();

	void PrintInfo();
	void PrintStudents();

	~Group();
private:
	void ExpandArray();
};