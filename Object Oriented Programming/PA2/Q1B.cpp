#include <iostream>
#include <stdlib.h>

using namespace std;

class Array2
{
	char *arr2;
	int size2;
	int counter = 0;

public:
	Array2(int x);
	char Add_element(char c);
	char delete_element();
	void peek();
	int  size();
	bool is_empty();
	bool is_full();
};

Array2::Array2(int x)
{
	size2 = x;
	arr2 = new char[size2];
	for (int i = 0; i < size2; i++)
	{
		arr2[i] = ' ';
	}
}
char Array2::Add_element(char c)
{	
	int i;
	for (i = 0; i < size2; i++)
	{
		if (arr2[i] == ' ')
		{
			break;
		}
	}

	for (int j = i; j > 0; j--)
	{
		arr2[j] = arr2[j - 1];
	}
	arr2[0] = c;
	return c;
}
char Array2::delete_element()
{
	char temp = arr2[0];
	int i;

	for (i = 0; i < size2; i++)
	{
		if (arr2[i] == ' ')
		{
			break;
		}
	}
	for (int j = 0; j < i; j++)
	{
		arr2[j] = arr2[j + 1];
	}

	return temp;
}
void Array2::peek()
{
	cout << arr2[0];
}
int  Array2::size()
{
	return size2;
}
bool Array2::is_empty()
{
	bool a;
	for (int i = 0; i < size2; i++)
	{
		if (arr2[i] != ' ')
		{
			return false;
		}
	}
	return true;
}
bool Array2::is_full()
{
	int x = 0;
	int i;
	for (i = 0; i < size2; i++)
	{
		if (arr2[i] != ' ')
		{
			x++;
		}
	}
	if (x == size2)
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
	int s2;
	cout << "Please enter the size of Array1 : ";
	cin >> s2;

	Array2 x(s2);

	int option;


	do
	{
		cout << "-------------------------------" << endl;
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


