#pragma once
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class Student
{
private:
	int roll_number, marks;
	string grade;

public:
	Student();
	void set(int, int, string);
	int get_rollNumber();
	int getmarks();
	string getGrade();
	friend void print(Student x);
};

