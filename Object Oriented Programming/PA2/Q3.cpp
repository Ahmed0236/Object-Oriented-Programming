#include <iostream>
#include <stdlib.h>
#include <string>
#include <math.h>

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
	void print();
};

Array1::Array1(int x)
{
	size1 = x;
	arr1 = new char[size1];
	for (int i = 0; i < size1; i++)
	{
		arr1[i] = ' ';
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
	char temp = '0' ;
	for (int i = size1 - 1; i >= 0; i--)
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
	int x = 0;
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
void Array1::print()
{
	for (int i = 0; i < size1; i++)
	{
		cout << arr1[i];
	}
	cout << endl;
}
/////////////////////////////////////////////////////////////////////////

class num1
{
	float *arr1;
	int size1;
public: 
	num1(int x);
	float Add_element(float c);
	float delete_element();
	void print();
	void peek();
};

num1::num1(int x)
{
	size1 = x;
	arr1 = new float[size1];
	for (int i = 0; i < size1; i++)
	{
		arr1[i] = ' ';
	}
}
float num1::Add_element(float c)
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
float num1::delete_element()
{
	float temp = ' ';
	for (int i = size1 - 1; i >= 0; i--)
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
void num1::print()
{
	for (int i = 0; i < size1; i++)
	{
		cout << arr1[i];
	}
	cout << endl;
}
void num1::peek()
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
/////////////////////Array works 2////////////////////////////////





class Array2
{
	char *arr2;
	int size2;
	int counter = 0;

public:
	Array2(int x);
	char Add_element(char c);
	char delete_element();
	char peek();
	int  size();
	bool is_empty();
	bool is_full();
	void print();

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
char Array2::peek()
{
	return arr2[0];
}
int  Array2::size()
{
	return size2;
}
bool Array2::is_empty()
{
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
void Array2::print()
{
	for (int i = 0; i < size2; i++)
	{
		cout << arr2[i];
	}
	cout << endl;
}
bool is_number(char x)
{
	if (x != '+' && x != '-' && x != '*'  && x != '/' && x != '%')
	{
		return true;
	}
	else
	{
		return false;
	}
}
/////////////////////////////////////////////////
class num2
{
	float *arr2;
	int size2;
public :
	num2(int x);
	float Add_element(float c);
	float delete_element();
	void print();
};
num2::num2(int x)
{
	size2 = x;
	arr2 = new float[size2];
	for (int i = 0; i < size2; i++)
	{
		arr2[i] = ' ';
	}
}
float num2::Add_element(float c)
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
float num2::delete_element()
{
	float temp = arr2[0];
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
void num2::print()
{
	for (int i = 0; i < size2; i++)
	{
		cout << arr2[i];
	}
	cout << endl;
}

///////////////////////////////////////////////////////////////////////

int  setWeight(char x)

{
	if (x == '+' || x == '-')
	{
		return 1;
	}

	else if (x == '*' || x == '/' || x == '%')
	{
		return 2;
	}
	return 0;
}
bool HasHigherprecedence(char stacktop, char expression)
{
	int weight_of_expression = setWeight(expression);
	int weight_stack_top = setWeight(stacktop);

	if (weight_stack_top >= weight_of_expression)
	{
		return true;
	}
	else
	{
		return false;
	}
}
float calculation(float a, float b, char sign)
{
	if (sign == '+')
	{	
		return (a+b);
	}
	else if (sign == '-')
	{
		return (b-a);
	}
	else if (sign == '*')
	{	
		return (a * b);
	}
	else if (sign == '/')
	{
		return (a / b);
	}
	else if (sign == '%')
	{
		return ( a -(a/b) );
	}
}
////////////////////////////////////////////////////////////////////////
int main()
{
	int s2;
	cout << "Please enter the size of Array1 : ";
	cin >> s2;

	//Array1 x(s2);

	char *exp = new char[s2];
	//populate array

	for (int i = s2-1; i >= 0; i--)
	{
		cin >> exp[i];
	}

	//create stack operants
	Array2 stack(s2);
	//postfix array
	Array1 postfix(s2);
	
	
	for (int i = 0; i < s2; i++)
	{	
		//if an operand add it to postfix which is arary1
		if (is_number(exp[i]) == true)
		{	
			postfix.Add_element(exp[i]);
			//postfix.peek();	
		}
		
		// if an operator add it to stack
		else if (is_number(exp[i]) == false)
		{
			while (!stack.is_empty() && HasHigherprecedence(stack.peek(), exp[i]))
			{
				postfix.Add_element(stack.peek());
				stack.delete_element();
			}
			stack.Add_element(exp[i]);
		}
		
	}

	while (!stack.is_empty())
	{
		postfix.Add_element(stack.delete_element());
	}
	//postfix.print();

	/////////////////////////////code for solving////////////////////////////////////////////////////
	char *temp = new char[s2];
	for (int i = 0; i < s2; i++)
	{
		temp[i] = postfix.delete_element();
	}
	
	cout << "Prefix notation : ";
	for (int i = 0; i < s2; i++)
	{
		cout << temp[i];
	}
	cout << endl;
	
//////////////////////////////////using array 1///////////////////////////////////
	num1 numbers(s2);
	Array1 sign1(s2);

	int m = 0, n = 0;
	int i = s2;
	while (i >= 0)
	{	
		//cout << "i is : " << i << endl;
		if (m >= 2 && n > 0)
		{
			numbers.Add_element(calculation(numbers.delete_element(), numbers.delete_element(), sign1.delete_element()));
			m--;
			n--;
			//cout << "calculation : ";
			//numbers.peek();
			//cout << endl;
			//cout << "m is : " << m << endl;
			//cout << "n is : " << n << endl;
		}

		else
		{
			if (is_number(temp[i]) == true)
			{	
				numbers.Add_element( (static_cast<int>(temp[i])-48) );
				m++;
				i--;
				//cout << "number added" << endl;
				//cout << "m is : " << m << endl;
			}
			else if (is_number(temp[i]) == false)
			{
				sign1.Add_element(temp[i]);
				n++;
				i--;
				//cout << "sign added" << endl;
				//cout << "n is : " << n << endl;
			}
		}
	}
	
	
	float x = numbers.delete_element();
	float y = numbers.delete_element();
	//cout << "my answer is " << 5 / 3 + 4 * 6 << endl;
	cout << "answer array1 : " << numbers.Add_element(calculation(x, y, sign1.delete_element())) << endl;
	

	num2 numbers2(s2);
	Array2 sign2(s2);

	m = 0;
	n = 0;
	i = s2;
	while (i >= 0)
	{
		//cout << "i is : " << i << endl;
		if (m >= 2 && n > 0)
		{
			numbers2.Add_element(calculation(numbers2.delete_element(), numbers2.delete_element(), sign2.delete_element()));
			m--;
			n--;
			//cout << "calculation : ";
			//numbers.peek();
			//cout << endl;
			//cout << "m is : " << m << endl;
			//cout << "n is : " << n << endl;
		}

		else
		{
			if (is_number(temp[i]) == true)
			{
				numbers2.Add_element((static_cast<int>(temp[i]) - 48));
				m++;
				i--;
				//cout << "number added" << endl;
				//cout << "m is : " << m << endl;
			}
			else if (is_number(temp[i]) == false)
			{
				sign2.Add_element(temp[i]);
				n++;
				i--;
				//cout << "sign added" << endl;
				//cout << "n is : " << n << endl;
			}
		}
	}

	x = numbers2.delete_element();
	y = numbers2.delete_element();
	cout << "ANSWER Array2 : " << numbers2.Add_element(calculation(x, y, sign2.delete_element())) << endl;









	/*int option;


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

	} while (option != 7 && !cin.fail());*/

	system("pause");
}



