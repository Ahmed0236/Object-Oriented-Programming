#pragma once
#include <iostream>
#include <string>
#include "EmployeePay.h"
#include "Employee.h"

using namespace std;

class HourlyPay : public EmployeePay
{
private:
	double Rate;
	double hours;
public:
	void setRate();
	double getRate();
	void SetHours();
	double getHours();
	void check();
	void print();

	HourlyPay();
	~HourlyPay();
};

