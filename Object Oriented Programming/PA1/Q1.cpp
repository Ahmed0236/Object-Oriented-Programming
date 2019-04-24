#include <iostream>
#include <cmath>
using namespace std;

void FindFreqDistribution(int valuesArray[], int FrequencyArray[], int inputSizeArray);


int main()
{
	
	int *myarr;
	int size;
	cout << "Please Enter the array size : " ;
	cin >> size;

	myarr = new int [size];
	
	cout << "PLease Enter the elements of the array" << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> myarr[i];
	}

	int *FreqArray =new int [size];
	int *Values = new int[size];
	for (int i = 0; i < size; i++)
	{
		Values[i] = myarr[i];
	}

	FindFreqDistribution(Values, FreqArray, size);
	delete[] myarr;
	system("Pause");
}


void FindFreqDistribution(int valuesArray[], int FrequencyArray[], int inputSizeArray)
{	

	int j = 0;
	//create copy;
	int *copy = new int[inputSizeArray];

	for (int i = 0; i < inputSizeArray; i++)
	{
		copy[i] = valuesArray[i];
	}

	for (int i = 0; i < inputSizeArray - 1; i++)
	{
		if (valuesArray[i] != valuesArray[i + 1])
		{
			valuesArray[j++] = valuesArray[i];
		}

	}

	valuesArray[j++] = valuesArray[inputSizeArray - 1];

	FrequencyArray = new int[j];

	//int freq[j];
	for (int i = 0; i < j; i++)
	{
		FrequencyArray[i] = 0;
	}
	
	int n = inputSizeArray;
	for (int m = 0; m < j; m++)
	{
		for (int i = 0; i < n; i++)
		{
			if (valuesArray[m] == copy[i])
			{
				FrequencyArray[m] = FrequencyArray[m] + 1;
			}
		}
	}
	for (int i = 0; i < j; i++)
	{

		cout << valuesArray[i] << " : " << FrequencyArray[i] << endl;
	}

	delete[]copy;
	delete[]FrequencyArray;
	delete[]valuesArray;
}