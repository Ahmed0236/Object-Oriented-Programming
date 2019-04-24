#include <iostream>
#include <string>
#include <stdlib.h>

#include "HourlyPay.h"
#include "EmployeePay.h"
#include "Employee.h"



using namespace std;

void PrintCheck(HourlyPay a)
{
	a.setEmployeeDetail();
	a.setAnnualPay();
	a.setWeeklyPay();
	a.setRate();
	a.SetHours();
	

	cout << "------------------------------" << endl;
	cout << "Name : " << a.getName() << endl;
	cout << "SSN : " << a.getSSN() << endl;
	cout << "ID : " << a.getID() << endl;
	cout << "Hours : " << a.getHours() << endl;
	cout << "Rate  " << a.getRate() << endl;
	a.print();
	
}


int main()
{
	HourlyPay a;
	PrintCheck(a);



	system("pause");
}