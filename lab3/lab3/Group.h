#pragma once
#define STUDENT_NULL {-1, "null"}

struct Student
{
	ulong id;
	const char* name;
};

class Group
{
	const char* _code;
	ulong _countStudents;
	ulong _maxCount;
	Student* _students;
public:
	Group();
	Group(const char* code);
	Group(const char* code, Student* students, ulong count);

	bool AddStudent(Student student);
	bool HasStudent(ulong id);
	bool RemoveStudent(ulong id);
	bool RenameGroup(const char* newCode);

	bool IsEmpty();
	ulong StudentsCount();
	Student Get(int index);
	const char* GetCode();

	void PrintInfo();
	void PrintStudents();

	~Group();
private:
	void ExpandArray();
};