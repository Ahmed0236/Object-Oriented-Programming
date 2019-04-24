#include <iostream>
#include "HourlyPay.h"
#include "EmployeePay.h"
#include "Employee.h"


using namespace std;

HourlyPay::HourlyPay()
{
	Rate = 0;
	hours = 0;
}

void HourlyPay::setRate()
{
	Rate = getWeeklyPay() / 40;
}
double HourlyPay::getRate()
{
	return Rate;
}

void HourlyPay::SetHours()
{	
	int temp;
	bool is_correct = true;
	
	do
	{	
		is_correct = true;
		cout << "Enter number of hours worked : ";
		cin >> temp;
		if (temp > 60)
		{	
			is_correct = false;
			cout << "Hours cannot be greater than 60 " << endl;
		}
	} while (is_correct != true);
	
	if (is_correct = true)
	{
		hours = temp;
	}

}



double HourlyPay::getHours()
{
	return hours;
}


void HourlyPay::check()
{	
	setRate();
	SetHours();
	
}

void HourlyPay::print()
{
	if (hours > 40 && hours <= 60)
	{
		cout << "Pay : " << (getHours() - 40)*getRate()*1.5 + (40 * getRate() )<< endl;
	}
	else
	{
		cout << "Pay : " << getHours() * getRate() << endl;
	}
}

HourlyPay::~HourlyPay()
{
}
