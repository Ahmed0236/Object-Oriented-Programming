#include <iostream>
#include <stdlib.h>

using namespace std;

class Array1
{
	char *arr1;
	int size1;
	int counter = 0;

public:
	Array1(int x);
	char Add_element(char c);
	char delete_element();
	void peek();
	int size();
	bool is_empty();
	bool is_full();
};

Array1::Array1(int x)
{
	size1 = x;
	arr1 = new char[size1];
	for (int i = 0; i < size1; i++)
	{
		arr1[i] = ' ' ;
	}
}
char Array1::Add_element(char c)
{
	for (int i = 0; i < size1; i++)
	{
		if (arr1[i] == ' ')
		{
			arr1[i] = c;
			break;
		}
	}
	return c;
}
char Array1::delete_element()
{	
	char temp;
	for (int i = size1-1; i >= 0; i--)
	{
		if (arr1[i] != ' ')
		{	
			temp = arr1[i];
			arr1[i] = ' ';
			break;
		}
	}
	return temp;
}
void Array1::peek()
{
	for (int i = size1 - 1; i >= 0; i--)
	{
		if (arr1[i] != ' ')
		{
			cout << arr1[i] << endl;
			break;
		}
	}
}
int  Array1::size()
{
	return size1;
}
bool Array1::is_empty()
{	
	bool a;
	for (int i = 0; i < size1; i++)
	{
		if (arr1[i] != ' ')
		{	
			return false;
		}
	}
	return true;
}
bool Array1::is_full()
{
	int x=0;
	int i;
	for (i = 0; i < size1; i++)
	{
		if (arr1[i] != ' ')
		{
			x++;
		}
	}
	if (x == size1)
	{
		return true;
	}
	else
	{
		return false;
	}
}


int main()
{	
	int s1;
	cout << "Please enter the size of Array1 : ";
	cin >> s1;

	Array1 x(s1);
	
	int option;

	do
	{
		cout << "---------------------------" << endl;
		cout << "Please select an option " << endl;
		cout << "1. Add  element" << endl;
		cout << "2. Delete Element" << endl;
		cout << "3. Peek" << endl;
		cout << "4. Size of array" << endl;
		cout << "5. Check if array is empty" << endl;
		cout << "6. Check if array is full" << endl;
		cout << "7. Exit" << endl;
		cin >> option;
		system("cls");

		switch (option)
		{
		case 1:
			if (x.is_full() == false)
			{
				char c;
				cout << "Enter element you want to enter : ";
				cin >> c;
				x.Add_element(c);
			}
			
			else
			{
				cout << "Array is Full Cannot enter more!" << endl;
			}
			break;

		case 2:
			if (x.is_empty() == false)
			{
				cout << "Deleted Element is : ";
				cout << x.delete_element();
				cout << endl;
			}
			else
			{
				cout << "Error : Array is Empty!" << endl;
			}

		break;

		case 3:
			cout << "Peek element is : ";
			x.peek();
			cout << endl;
			break;

		case 4:
			cout << "Size of array is : ";
			cout << x.size();
			cout << endl;
			break;

		case 5:
			cout << x.is_empty();
			cout << endl;
			break;

		case 6:
			cout << x.is_full();
			cout << endl;
			break;

		case 7:
			cout << "Program will exit now!" << endl;
			break;

		default:
			cout << "Invalid option " << endl;
			break;
		}
		
	} while (option != 7 && !cin.fail());


	system("pause");
}


