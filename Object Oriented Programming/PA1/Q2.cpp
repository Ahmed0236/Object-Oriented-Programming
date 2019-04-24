#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <ctype.h>



using namespace std;

class Word_index
{
public:
	Word_index(string);
	void Sort(vector <string>);
};


void Word_index::Sort(vector <string> a)
{
	sort(a.begin(), a.end());
	a.erase(std::unique(a.begin(), a.end()), a.end());
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << endl;
	}
}








Word_index::Word_index(string filename)
{
	ifstream myfile;
	string word;
	vector <string> wordsVector;
	vector <string> withoutdupicate;
	string line;
	vector <string> lineVector;

	myfile.open(filename);
	if (myfile.is_open())
	{
		string word;
		while (myfile >> word)
		{
			//this removes commas and full stops
			int length = word.length();
			for (int i = 0; i < length; i++)
			{
				if (word[i] == ',' || word[i] == '.')
				{
					word = word.substr(0, length - 1);
				}
			}
			// TO DO remove unwanted characters from word
			//cout << word << endl;  //Just for testing
			wordsVector.push_back(word);
		}

		cout << "Here is the Sorted list of Alphabets " << endl << endl;
		Sort(wordsVector);
		cout << "----------------------------------------------------------------------------------------" << endl << endl;
		//remove duplicate
		sort(wordsVector.begin(), wordsVector.end());

		for (int i = 0; i < wordsVector.size(); i++)
		{
			string str;
			char c;
			int j = 0;
			str = wordsVector[i];
			while (str[j])
			{
				c = str[j];
				str[j] = tolower(c);
				j++;
			}
			wordsVector[i] = str;
		}

		
		sort(wordsVector.begin(), wordsVector.end());
		wordsVector.erase(std::unique(wordsVector.begin(), wordsVector.end()), wordsVector.end());

		//	for (int i = 0; i < wordsVector.size(); i++)
		{
			//cout << wordsVector[i] << endl;
		}
	}
	else
	{
		cout << "Unable to open file" << endl;
	}
	myfile.close();





	myfile.open(filename);
	if (myfile.is_open())
	{

		while (getline(myfile, line))
		{
			//cout << line << endl << endl;
			lineVector.push_back(line);
		}
		myfile.close();
	}
	else
	{
		cout << "Unable to open file" << endl;
	}




	for (int i = 0; i < lineVector.size(); i++)
	{
		string str;
		char c;
		int j = 0;
		str = lineVector[i];
		while (str[j])
		{
			c = str[j];
			if (c != 'I')
			{
				str[j] = tolower(c);
			}
			
			j++;
		}
		lineVector[i] = str;
	}
	//cout << lineVector.size() << endl;


	//find the line number now
	for (int i = 0; i < wordsVector.size(); i++)
	{
		int counter = 0;
		string y = wordsVector[i];
		cout << y << " : ";

		for (int j = 0; j < lineVector.size(); j++)
		{
			int k = 0;
			int t;
			int len = lineVector[j].length();

			string x = lineVector[j];

			while (k < len)
			{

				size_t found = x.find(y);

				//cout << x << endl;
				if (found != std::string::npos)
				{
					t = x.length();
					cout << j << " ";
					x = x.substr(found + y.length(), t - found - y.length());
				}
	
				k++;
				//cout << k << endl;
				//cout << j << endl;
			}


		}
		cout << endl;
	}
}









int main()
{	
	Word_index myword("test.txt");
	system("Pause");
}