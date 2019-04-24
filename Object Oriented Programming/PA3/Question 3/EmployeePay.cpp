#include "HourlyPay.h"
#include "EmployeePay.h"
#include "Employee.h"
#include <iostream>
#include <string>

using namespace std;

EmployeePay::EmployeePay()
{
	Annual_pay = 0;
	WeeklyPay = 0;
}

void EmployeePay::setAnnualPay()
{	
	double temp;
	bool is_correct = true;
	
	do
	{	
		is_correct = true;
		cout << "Enter Annual Pay :";
		cin >> temp;
		if (temp < 0)
		{
			cout << "Pay cannot be less than zero" << endl;
			is_correct = false;
		}
	} while (is_correct != true);
	
	
		Annual_pay = temp;
	
}

void EmployeePay::setWeeklyPay()
{	
	WeeklyPay = getAnnualpay() / 52;
}

double EmployeePay::getAnnualpay()
{
	return Annual_pay;
}


double EmployeePay::getWeeklyPay()
{
	return WeeklyPay;
}


EmployeePay::~EmployeePay()
{
}
