#include <iostream>
#include <string>
using namespace std;


class Human
{
protected:
	string name;
	int age;

public:
	virtual void print() = 0;
	//virtual double getTax() = 0;
	Human()
	{
		name = "";
		age = 0;
	}
	Human(string s, int b)
	{
		name = s;
		age = b;
	}
	string getname()
	{
		return name;
	}
	int getage()
	{
		return age;
	}
	void setname()
	{
		cout << "Enter Person name : ";
		cin.ignore();
		getline(cin, name);
		cout << endl;
	}
	void setage()
	{
		cout << "Enter Person Age : ";
		cin >> age;
		cout << endl;
	}
};


class Student :protected Human
{
protected:
	int n;
	int rollnum;
	string uniname;
	string *courses;
	int stipend;
	double Tax;

public:
	Student()
	{
		int n = 0;
		int rollnum = 0;
		string uniname = "";
		string *courses = NULL;
		int stipend = 0;
	}
	Student(int a, string b, string c[], int numcourses, int d)
	{
		rollnum = a;
		uniname = b;
		stipend = d;
		n = numcourses;

		courses = new string[n];
		for (int i = 0; i < n; i++)
		{
			courses[i] = c[i];
		}
	}
	int getrollnum()
	{
		return rollnum;
	}
	string getUni()
	{
		return uniname;
	}
	int getstipend()
	{
		return stipend;
	}
	void getCourses()
	{
		for (int i = 0; i < n; i++)
		{
			cout << "Course # " << i + 1 << " " << courses[i] << endl;
		}
	}

	void setrollnum()
	{
		cout << "Roll Number : ";
		cin >> rollnum;
		cout << endl;
	}
	void setUni()
	{
		cout << "University name : ";
		cin.ignore();
		getline(cin, uniname);
		cout << endl;
	}
	void setCourses()
	{
		int x;
		cout << "How many courses : ";
		cin >> x;
		n = x;

		courses = new string[n];
		cout << "Please enter list of courses " << endl;
		cin.ignore();
		for (int i = 0; i < n; i++)
		{
			getline(cin, courses[i]);
		}
		cout << endl;
	}
	void setStipend()
	{
		cout << "Stipend : ";
		cin >> stipend;
		cout << endl;
	}
	void setStudentDetails()
	{	
		peche:
		setname();
		setage();
		setrollnum();
		setUni();
		setCourses();
		setStipend();
		setTax();
		
		string x;
		cout << "Do you want to change your details (Y/N) " << endl;
		cin >> x;
		if (x == "Y" || x == "y")
		{
			goto peche;
		}

	}

	void setTax()
	{
		if (stipend > 50000)
		{
			Tax = 0.02 * stipend;
		}
		else
		{
			Tax = 0;
		}
	}

	double getTax()
	{
		return Tax;
	}


	void print()
	{
		cout << "------------------------" << endl;
		cout << "Student Details" << endl;
		cout << "Name : " << getname() << endl;
		cout << "Age : " << getage() << endl;
		cout << "Roll Number : " << getrollnum() << endl;
		cout << "University : " << getUni() << endl;
		cout << "Stipend : " << getstipend() << endl;
		cout << "TAX payable : " << getTax() << endl << endl;
		cout << "Course List :-" << endl;
		getCourses();
		cout << "-------------------------" << endl;
	}

	void printall()
	{	
		cout << "------------------------" << endl;
		cout << "Person type = ALL " << endl;
		cout << "Name : " << getname() << endl;
		cout << "Age : " << getage() << endl;
		cout << "Roll Number : " << getrollnum() << endl;
		cout << "University : " << getUni() << endl;
		cout << "Stipend : " << getstipend() << endl;
		cout << "TAX payable : " << getTax() << endl << endl;
		cout << "Course List :-" << endl;
		getCourses();
		cout << endl;
	}
};


class Employee : protected Human
{
protected:
	int EmpID;
	string compName;
	string *Languages;
	int salary;
	int numlang;
	double Tax;

public:
	Employee()
	{
		EmpID = 0;
		compName = "";
		Languages = NULL;
		salary = 0;
		numlang = 0;
	}
	Employee(int id, string name, string lang[], int nlang, int sal)
	{
		EmpID = id;
		compName = name;
		salary = sal;
		numlang = nlang;

		Languages = new string[numlang];
		for (int i = 0; i < numlang; i++)
		{
			Languages[i] = lang[i];
		}

	}
	int getEmpID()
	{
		return EmpID;
	}
	string getCompany()
	{
		return compName;
	}
	int getSalary()
	{
		return salary;
	}
	void getLanguages()
	{
		for (int i = 0; i < numlang; i++)
		{
			cout << "Langauge # " << i + 1 << " " << Languages[i] << endl;
		}
	}

	void setEmpID()
	{
		cout << "Enter Employee ID : ";
		cin >> EmpID;
		cout << endl;
	}
	void setCompany()
	{
		cout << "Enter Company Name : ";
		cin.ignore();
		getline(cin, compName);
		cout << endl;
	}
	void setSalary()
	{
		cout << "Enter Salary : ";
		cin >> salary;
		cout << endl;
	}
	void setLanguages()
	{
		int x;
		cout << "How many Languages : ";
		cin >> x;

		numlang = x;

		Languages = new string[numlang];
		cout << "Enter languages below " << endl;
		cin.ignore();
		for (int i = 0; i < numlang; i++)
		{
			getline(cin, Languages[i]);
		}
		cout << endl;
	}

	void setTax()
	{
		if (salary > 50000 && salary < 100000)
		{
			Tax = 0.05 * salary;
		}

		else if (salary > 100000)
		{
			Tax = salary * 0.10;
		}
		else
		{
			Tax = 0;
		}
	}

	double getTax()
	{
		return Tax;
	}

	void setEmployeeDetails()
	{	
		peche:
		setname();
		setage();
		setEmpID();
		setCompany();
		setSalary();
		setTax();
		setLanguages();

		string x;
		cout << "Do you want to change your details (Y/N) " << endl;
		cin >> x;
		if (x == "Y" || x == "y")
		{
			goto peche;
		}
	}

	void setEmployeeDetails2()
	{	
		peche:
		setEmpID();
		setCompany();
		setSalary();
		setTax();
		setLanguages();

		string x;
		cout << "Do you want to change your details (Y/N) " << endl;
		cin >> x;
		if (x == "Y" || x == "y")
		{
			goto peche;
		}
	}

	void print()
	{
		cout << "-------------------------" << endl;
		cout << "     Employee Details " << endl;
		cout << "Name : " << getname() << endl;
		cout << "Age : " << getage() << endl;
		cout << "Employee ID : " << getEmpID() << endl;
		cout << "Company Name : " << getCompany() << endl;
		cout << "Salary : " << getSalary() << endl;
		cout << "Tax Payable RS : " << getTax() << endl;
		getLanguages();
		cout << "-------------------------" << endl;
	}

	void printall()
	{	
		cout << endl;
		cout << "Employee ID : " << getEmpID() << endl;
		cout << "Company Name : " << getCompany() << endl;
		cout << "Salary : " << getSalary() << endl;
		cout << "Tax Payable RS : " << getTax() << endl;
		getLanguages();
		cout << endl;
	}
};

class Businessman : protected Human
{
protected:
	int regID;
	string companyName;
	int earning;
	double Tax;

public:
	
	Businessman()
	{
		regID = 0;
		companyName = "";
		earning = 0;
	}
	Businessman(int a, string b, int c)
	{
		regID = a;
		companyName = b;
		earning = c;
	}
	int getRegID()
	{
		return regID;
	}
	string getCompanyname()
	{
		return companyName;
	}
	int getEarning()
	{
		return earning;
	}

	void setRegID()
	{
		cout << "Enter Registration ID : ";
		cin >> regID;
		cout << endl;
	}
	void setcompanyname()
	{
		cout << "Company name : ";
		cin.ignore();
		getline(cin, companyName);
		cout << endl;
	}
	void setEarning()
	{
		cout << "Earning : ";
		cin >> earning;
		cout << endl;
	}
	
	void setTax()
	{
		if (earning > 50000 && earning < 100000)
		{
			Tax = 0.08* earning;
		}
		else if (earning > 100000)
		{
			Tax = 0.12 * earning;
		}
	}

	double getTax()
	{
		return Tax;
	}

	void setBusinessmanDeatils()
	{	
		peche:
		setname();
		setage();
		setRegID();
		setcompanyname();
		setEarning();
		setTax();

		string x;
		cout << "Do you want to change your details (Y/N) " << endl;
		cin >> x;
		if (x == "Y" || x == "y")
		{
			goto peche;
		}
		

	}

	void setBusinessDetails2()
	{	
		peche:
		setRegID();
		setcompanyname();
		setEarning();
		setTax();

		string x;
		cout << "Do you want to change your details (Y/N) " << endl;
		cin >> x;
		if (x == "Y" || x == "y")
		{
			goto peche;
		}
	}


	void print()
	{
		cout << "------------------------------------" << endl;
		cout << "           Businessman Details" << endl;
		cout << "Name : " << getname() << endl;
		cout << "Age : " << getage() << endl;
		cout << "Registration ID : " << getRegID() << endl;
		cout << "Company Name : " << getCompanyname() << endl;
		cout << "Earnings : " << getEarning() << endl;
		cout << "Tax Payable RS: " << getTax() << endl;
		cout << "-------------------------------------" << endl;

	}

	void printall()
	{
		cout << "Registration ID : " << getRegID() << endl;
		cout << "Company Name : " << getCompanyname() << endl;
		cout << "Earnings : " << getEarning() << endl;
		cout << "Tax Payable RS: " << getTax() << endl;
		cout << "-------------------------------------" << endl;
	}
};

class Person :private Student, Employee, Businessman
{
protected:
	bool is_student;
	bool is_employee;
	bool is_businessman;
	bool is_all;

public:
	Person()
	{
		is_student = 0;
		is_employee = 0;
		is_businessman = 0;
		is_all = 0;
		//Type();
	}
	Person(bool a, bool b, bool c)
	{
		is_student = a;
		is_employee = b;
		is_businessman = c;
	}
	bool is_Student()
	{
		return is_student;
	}
	bool is_Employee()
	{
		return is_employee;
	}
	bool is_Businessman()
	{
		return is_businessman;
	}
	bool is_All()
	{
		return is_all;
	}

	void Type()
	{
		int option;
		cout << "Select Person type" << endl;
		cout << "1. Student" << endl;
		cout << "2. Employee" << endl;
		cout << "3. Businessman" << endl;
		cout << "4. All of the above" << endl;
		cin >> option;


		if (option == 1)
		{	
			is_student = true;
			setStudentDetails();
			//Student::print();

		}
		else if (option == 2)
		{	
			is_employee = true;
			setEmployeeDetails();
			//Employee::print();
		}
		else if (option == 3)
		{	
			is_businessman = true;
			setBusinessmanDeatils();
			//Businessman::print();
		}
		else if (option == 4)
		{	
			is_all = true;
			setStudentDetails();
			setEmployeeDetails2();
			setBusinessDetails2();

			//Student::printall();
			//Employee::printall();
			//Businessman::printall();
			
		}
	}

	void print()
	{
		if (is_Student() == true)
		{
			Student::print();
		}

		else if (is_Businessman() == true)
		{
			Businessman::print();
		}
		else if (is_Employee() == true)
		{
			Employee::print();
		}
		else if (is_all == true)
		{
			Student::printall();
			Employee::printall();
			Businessman::printall();
			cout << endl;
			cout << "Total Tax Payable  : " << Tax() << endl;
		}
	}

	double Tax()
	{	
	
		if (is_Student() == true)
		{
			 return Student::getTax();
		}
		else if (is_Employee() == true)
		{
			return Employee::getTax();
		}
		else if (is_Businessman() == true)
		{
			 return Businessman::getTax();
		}
		else if (is_All() == true)
		{
			return (Student::getTax() + Employee::getTax() + Businessman::getTax());
		}
		return 0;
	}

};





///////////////////////////////////////////
template <typename T>
void Sort(T a[], int size)
{	
	int option;
	cout << "1. Ascending " << endl;
	cout << "2. Descending" << endl;
	cin >> option;

	if (option == 1)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (a[i].Tax() < a[j].Tax())
				{
					T temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}
		}
	}

	else if (option == 2)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (a[i].Tax() > a[j].Tax())
				{
					T temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}
		}
	}
	
	for (int i = 0; i < size; i++)
	{	
		cout << "Person # " << i + 1 << endl;
		a[i].print();
	}
}








int main()
{
	int n;
	cout << "How many people : ";
	cin >> n;

	Person *a = new Person[n];

	
	for (int i = 0; i < n; i++)
	{
		a[i].Type();
		a[i].print();
	}

	Sort(a, n);

	

	system("pause");
}