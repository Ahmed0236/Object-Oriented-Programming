#include "HourlyPay.h"
#include "EmployeePay.h"
#include "Employee.h"
#include <string>
#include <iostream>

using namespace std;




Employee::Employee()
{	
	//setEmployeeDetail();

}

void Employee::setName()
{	
	cout << "Enter name :";
	//cin.ignore();
	getline(cin, EmployeeName);
}


void Employee::setSSN()
{	
	string temp;
	bool is_correct = false;

	do
	{
		cout << endl;
		cout << "Enter SSN in the format as below" << endl;
		cout << "xxx-xx-xxxx" << endl;
		cin >> temp;

		is_correct = true;

		if (temp.length() != 11)
		{
		is_correct = false;
		cout << "Ivalid SSN format" << endl;
		}

		else
		{
			for (int i = 0; i < 11; i++)
			{
				if (i != 3 && i != 6)
				{
					if (temp.substr(i, 1) != "1" && temp.substr(i, 1) != "2" && temp.substr(i, 1) != "3" && temp.substr(i, 1) != "4" &&
						temp.substr(i, 1) != "5" && temp.substr(i, 1) != "6" && temp.substr(i, 1) != "7" && temp.substr(i, 1) != "8" &&
						temp.substr(i, 1) != "9" && temp.substr(i, 1) != "0")
					{
						is_correct = false;
						cout << "Ivalid SSN format " << endl;
						break;
					}
					else
					{
						//is_correct = true;
					}
				}

				if (i == 3 || i == 6)
				{
					if (temp.substr(3, 1) != "-" && temp.substr(6, 1) != "-")
					{
						is_correct = false;
						cout << "Invalid SSN format " << endl;
						break;
					}
					else
					{
						//is_correct = true;
					}
				}


			}
		}

		} while (is_correct == false);

		
		


	if (is_correct = true)
	{
		ssn = temp;
	}

}

void Employee::setID()
{
	string temp;
	bool is_correct = true;


	do
	{	
		cout << "Enter Employee ID as below format" << endl;
		cout << "xxx-L" << endl;
		cin >> temp;

		is_correct = true;

		if (temp.length() != 5)
		{
			is_correct = false;
		}

		else
		{
			for (int i = 0; i < 3; i++)
			{
				
					if (temp.substr(i, 1) != "1" && temp.substr(i, 1) != "2" && temp.substr(i, 1) != "3" && temp.substr(i, 1) != "4" &&
						temp.substr(i, 1) != "5" && temp.substr(i, 1) != "6" && temp.substr(i, 1) != "7" && temp.substr(i, 1) != "8" &&
						temp.substr(i, 1) != "9" && temp.substr(i, 1) != "0")
					{
						is_correct = false;
						cout << "Invalid format 1" << endl;
						break;
					}
					else
					{
						is_correct = true;
					}
			}

					//check  for hiphen
					if (temp.substr(3, 1) != "-")
					{
						is_correct = false;
						cout << "Invalid Format " << endl;
					}
					
				

				//check for char
					if (temp.substr(4, 1) < "A" || temp.substr(4, 1) > "M")
					{
						is_correct = false;
						cout << "Invalid Format " << endl;
					}
			
				


			
		}

	} while (is_correct == false);

	
	if (is_correct == true)
	{
		EmpID = temp;
	}

}

void Employee::setEmployeeDetail()
{
	setName();
	setSSN();
	setID();
}



string Employee::getID()
{
	return EmpID;
}

string Employee::getSSN()
{
	return ssn;
}

string Employee::getName()
{
	return EmployeeName;
}

void Employee::print()
{	

}

Employee::~Employee()
{
}
