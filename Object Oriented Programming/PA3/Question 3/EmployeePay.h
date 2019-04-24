#pragma once
#include <iostream>
#include <string>
#include "Employee.h"
#include "HourlyPay.h"


using namespace std;


class EmployeePay: public Employee
{
private:
	double Annual_pay;
	double WeeklyPay;
	
public:
	void setAnnualPay();
	double getAnnualpay();
	void setWeeklyPay();
	double getWeeklyPay();
	
	EmployeePay();
	~EmployeePay();
};

