#pragma once
#include <iostream>
#include <string>
#include "HourlyPay.h"
#include "EmployeePay.h"

using namespace std;


class Employee
{
private:
	string EmployeeName;
	string ssn;
	string EmpID;

public:
	Employee();
	void setID();
	void setName();
	void setSSN();
	void setEmployeeDetail();

	string getName();
	string getSSN();
	string getID();
	
	void print();
	~Employee();
};

