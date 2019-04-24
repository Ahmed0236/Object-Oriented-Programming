#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <string>
#include <math.h>
#include <string.h>
#include "Q3.h"

using namespace std;

void Grader(int marks[], string grade[], int n)
{

	for (int i = 0; i < n; i++)
	{


		if (marks[i] > 89)
		{
			grade[i] = "A+";
		}
		else if (marks[i] > 79)
		{
			grade[i] = 'A';
		}
		else if (marks[i] > 69)
		{
			grade[i] = 'B';
		}
		else if (marks[i] > 59)
		{
			grade[i] = 'C';
		}
		else if (marks[i] > 49)
		{
			grade[i] = 'D';
		}
		else
		{
			grade[i] = 'F';
		}

	}
}
void DesiredStudent(int& roll, Student a[])
{	
	int i;
	for (i = 0; i < 100; i++)
	{
		if (roll == a[i].get_rollNumber())
		{
			break;
		}
	}

	print(a[i]);
}
void HighestScore(Student b[])
{
	int MAX = 0;
	int i,j;
	for (i = 0; i < 100; i++)
	{
		if (b[i].getmarks() > MAX)
		{
			MAX = b[i].getmarks();
		}
	}
	for (j = 0; j < 100; j++)
	{
		if (b[j].getmarks() == MAX)
		{
			break;
		}
	}
	print(b[j]);
}
void AvgResult(Student c[])
{
	int i;
	double sum = 0;
	double avg = 0;
	for (int i = 0; i < 100; i++)
	{
		sum = sum + c[i].getmarks();
	}
	avg = sum / 100;

	cout << "Class Average marks are : " << avg << endl;
}
void Calculations(Student d[])
{	
	int counter;
	int MAX = 0;
	int mode;
	for (int i = 0; i < 100; i++)
	{
		counter = 0;
		for (int j = i; j < 100; j++)
		{
			if (d[i].getmarks() == d[j].getmarks())
			{
				counter++;
			}
		}
		if (counter > MAX)
		{
			MAX = counter;
			mode = d[i].getmarks();
		}

	}


	int marks[100];
	for (int i = 0; i < 100; i++)
	{
		marks[i] = d[i].getmarks();
	}


	int temp, median;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (marks[i] < marks[j])
			{
				temp = marks[i];
				marks[i] = marks[j];
				marks[j] = temp;
			}
		}
	}
	median = marks[100 / 2];
	
	double sum = 0;
	double avg = 0;
	for (int i = 0; i < 100; i++)
	{

		sum = sum + marks[i];
	}
	avg = sum / 100;

	double diff = 0;
	for (int i = 0; i < 100; i++)
	{
		diff = diff + pow((marks[i] - avg), 2);
	}

	double var = diff / 100;
	double sd = sqrt(var);


	cout << "Mean   : " << avg << endl;
	cout << "Mode   : " << mode << endl;
	cout << "Median : " << median << endl;
	cout << "Var    : " << var << endl;
	cout << "Sd     : " << sd << endl;

}
void Sorter(Student e[])
{	
	int option;
	cout << "Select Sorting Criteria " << endl;
	cout << "1. Roll Number" << endl;
	cout << "2. Marks" << endl;
	cout << "3. Grade" << endl;
	cin >> option;
	cout << endl;

	//copy to temp array
	if (option == 1)
	{	
		int roll[100];
		for (int i = 0; i < 100; i++)
		{
			roll[i] = e[i].get_rollNumber();
		}

		int temp ;
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				if (roll[i] < roll[j])
				{
					temp = roll[i];
					roll[i] = roll[j];
					roll[j] = temp;
				}
			}
		}


		ofstream myfile;
		myfile.open("Sorted_Students.txt");
		myfile.clear();
		for (int i = 0; i < 100; i++)
		{	
			for (int j = 0; j < 100; j++)
			{
				if (roll[i] == e[j].get_rollNumber())
				{
					myfile << roll[i] << "," << e[j].getmarks() << "," << e[j].getGrade() << endl;
				}
			}
		
		}
		myfile.close();
	}

	if (option == 2)
	{
		int marks[100];
		for (int i = 0; i < 100; i++)
		{
			marks[i] = e[i].getmarks();
		}

		int temp;
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				if (marks[i] > marks[j])
				{
					temp = marks[i];
					marks[i] = marks[j];
					marks[j] = temp;
				}
			}
		}


		ofstream myfile;
		myfile.open("Sorted_Students.txt");
		myfile.clear();
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				if (marks[i] == e[j].getmarks())
				{
					myfile << e[j].get_rollNumber() << "," << marks[i]
					<< "," << e[j].getGrade() << endl;
				}
			}

		}
		myfile.close();
	}

	if (option == 3)
	{
		string grade[100];
		for (int i = 0; i < 100; i++)
		{
			grade[i] = e[i].getGrade();
		}

		string temp;
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				if (grade[i] < grade[j])
				{
					temp = grade[i];
					grade[i] = grade[j];
					grade[j] = temp;
				}
			}
		}

		int j;
		for (j = 0; j < 100; j++)
		{
			if (grade[j] == "B")
			{
				break;
			}
		}

		int m;
		for (m = 0; m < j; m++)
		{
			for (int n = 0; n < j; n++)
			{
				if (grade[m] > grade[n])
				{
					temp = grade[m];
					grade[m] = grade[n];
					grade[n] = temp;
				}
			}
		}


		ofstream myfile;
		myfile.open("Sorted_Students.txt");
		myfile.clear();
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				if (grade[i] == e[j].getGrade())
				{
					myfile << e[j].get_rollNumber() << "," << e[j].getmarks() 
						<< "," << grade[i] << endl;
				}
			}

		}
		myfile.close();
	}
	

}
/////////////////////////////////////////////////////////////////////////
Student::Student()
{
	roll_number = 1;
	marks = 85;
	grade = "A";
}
void Student::set(int a, int b, string c)
{
	roll_number = a;
	marks = b;
	grade = c;
}
int Student::get_rollNumber()
{
	return roll_number;
}
int Student::getmarks()
{
	return marks;
}
string Student::getGrade()
{
	return grade;
}
void print(Student x)
{
	cout << "Student " << x.get_rollNumber() << " has " << x.getmarks() << " Marks and got " << x.getGrade() << " Grade " << endl;
}
/////////////////////////////////////////////////////////////////////////////

int main()
{	
	peche:
	srand(time(NULL));
	int roll[100], marks[100], temp;
	string grades[100];

	ofstream myfile;
	myfile.open("student.txt");
	myfile.clear();
	int i = 0;
	
	//generate 100 unique random numbers
	while (i < 100)
	{	
		bool same = 0;
		temp = rand() % 100 + 1;
		//cout << temp << endl;
		for (int j = 0; j < i; j++)
		{
			if (temp == roll[j])
			{	
				//cout << "break" << endl;
				same = true;
				break;
			}
		}

		if (same == false)
		{
			roll[i] = temp;
			marks[i] = (rand() % (95 - 25 + 1)) + 25;
			i++;
		}
		
	}
	
	//run grader
	Grader(marks, grades, 100);
	
	//write data to file
	for (int i = 0; i < 100; i++)
	{
		myfile << roll[i] << "," << marks[i] << "," << grades[i] << endl;
	}
	
	myfile.close();

	//////////////////////////////////////////////Part 3///////////////////////////////////////////////////////////////
	
	Student CS200[100];
	ifstream myfile2;
	myfile2.open("student.txt");
	
	int MARKS, ROLL;
	string GRADE;
	
	string line;
	int index = 0;
	//read the file
	while( getline(myfile2, line))
	{	
		int len = line.length();
		
		int i, j, k;

		for (i = 0; i < len; i++)
		{
			if (line.substr(i, 1) == ",")
			{
				//cout << "vgfctgj" << endl;
				ROLL = stoi(line.substr(0, i));
				break;
			}
		}

		//cout << i;
		for (j = i + 2; j < len; j++)
		{
			if (line.substr(j, 1) == ",")
			{
				//cout << "vgfctgj" << endl;
				MARKS = stoi(line.substr(i + 1, j - i - 1));
				break;
			}
		}


		GRADE = line.substr(j + 1, len - j - 1);
		CS200[index].set(ROLL, MARKS, GRADE);
		index++;
	}

	int option;
	do
	{	
		cout << endl;
		cout << "----------------------------------" << endl;
		cout << "Please select an option" << endl;
		cout << "1. Desired Student" << endl;
		cout << "2. Highest Scorrer" << endl;
		cout << "3. Class Average Marks" << endl;
		cout << "4. Create new file" << endl;
		cout << "5. Further Calulations" << endl;
		cout << "6. Sorter" << endl;
		cout << "7. Exit" << endl;
		
		cout << endl;
		cin >> option;
		cout << endl;

		switch (option)
		{
		case 1:
			int des;
			cout << "enter roll number to find : ";
			cin >> des;
			DesiredStudent(des, CS200);
			break;

		case 2:
			HighestScore(CS200);
			break;

		case 3:
			AvgResult(CS200);
			break;

		case 4:
			cout << "A new file has been created" << endl;
			goto peche;
			break;

		case 5:
			Calculations(CS200);
			break;

		case 6:
			Sorter(CS200);
			break;

		case 7:
			cout << "Promgram will end now!" << endl;
			cout << "Goodbye" << endl << endl;
			break;

		default:
			cout << endl;
			cout << "Invalid Option" << endl;
			break;
		}
	} while (option != 7);
	
	
	myfile2.close();
	system("pause");
}



							