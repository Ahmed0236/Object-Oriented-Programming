#include <iostream>
#include <string>
using namespace std;

class Food
{
protected:
	string fruits[5];
	int fruits_calories[5];
	string vegetables[5];
	int vegetables_calories[5];
	string nuts[5];
	int nuts_calories[5];

public:
	void Fruits();
	void Vegetables();
	void Nuts();

};

void Food::Fruits()
{
	fruits[0] = "Apple_25";
	fruits[1] = "Guava_55";
	fruits[2] = "Banana_10";
	fruits[3] = "Mango_60";
	fruits[4] = "Peach_15";

	fruits_calories[0] = 25;
	fruits_calories[1] = 55;
	fruits_calories[2] = 10;
	fruits_calories[3] = 60;
	fruits_calories[4] = 15;

	// display
	for (int i = 0; i < 5; i++)
	{
		cout << fruits[i] << endl;
	}
	cout << endl;
}
void Food::Vegetables()
{
	vegetables[0] = "Broccoli_44";
	vegetables[1] = "Onion_14";
	vegetables[2] = "Peas_47";
	vegetables[3] = "Potato_88";
	vegetables[4] = "Capsicum_20";

	vegetables_calories[0] = 44;
	vegetables_calories[1] = 14;
	vegetables_calories[2] = 47;
	vegetables_calories[3] = 88;
	vegetables_calories[4] = 20;


	// display
	for (int i = 0; i < 5; i++)
	{
		cout << vegetables[i] << endl;
	}
	cout << endl;
}
void Food::Nuts()
{
	nuts[0] = "Almonds_80";
	nuts[1] = "Cacao_85";
	nuts[2] = "Coconut_62";
	nuts[3] = "Hazelnut_77";
	nuts[4] = "Cashew_90";

	nuts_calories[0] = 80;
	nuts_calories[1] = 85;
	nuts_calories[2] = 62;
	nuts_calories[3] = 77;
	nuts_calories[4] = 90;

	// display
	for (int i = 0; i < 5; i++)
	{
		cout << nuts[i] << endl;
	}
	cout << endl;
}

class Detail :protected Food
{
private:
	int threshold;
	string cart[4];
public:
	Detail();
	void Take();
	void Print();
};

Detail::Detail()
{
	Fruits();
	Vegetables();
	Nuts();
}


void Detail::Take()
{
	int x;
	cout << "How many Calories you want to consume : ";
	cin >> x;
	threshold = x;
}

void Detail::Print()
{
	int combinations = 0;
	int cal_count = 0;



	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				for (int l = k + 1; l < 5; l++)
				{
					if (fruits_calories[i] + vegetables_calories[j] + nuts_calories[k] + nuts_calories[l] <= threshold)
					{
						//add to cart
						cart[0] = fruits[i];
						cart[1] = vegetables[j];
						cart[2] = nuts[k];
						cart[3] = nuts[l];
						combinations++;

						cal_count = fruits_calories[i] + vegetables_calories[j] + nuts_calories[k] + nuts_calories[l];

						for (int p = 0; p < 4; p++)
						{
							cout << cart[p] << endl;
						}
						cout << "Total Calories : " << cal_count << endl << endl;
						cout << "--------------------------------------" << endl;
					}
				}
			}
		}
	}

	cout << "Total Combinations : " << combinations << endl;
	

}

//must contain one fruit, one vegetable, and two nuts

int main()

{
	Detail Chandler;
	Chandler.Take();
	Chandler.Print();

	//Chandler.Print();
	/*PDC.Fruits();
	PDC.Vegetables();
	PDC.Nuts();*/




	system("pause");
}