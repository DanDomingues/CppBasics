#include <string>
#include <iostream>
#include <vector>

using namespace std;

void drawLetterPyramid(string s)
{
	string composite;
	for(auto i {0}; i < s.length(); i++)
	{
		string composite = s.substr(i, 1);
		
		string suffix, prefix, spacing;
		for(auto j {i - 1}; j >= 0; j--)
		{
			suffix += s.at(j);
		}
		for(auto j {0}; j < i; j++)
		{
			prefix += s.at(j);
		}
		spacing = string(s.length() - i, ' ');	
		cout << spacing << prefix << composite << suffix << endl;
	}
}

int main(int argc, char **argv)
{
	vector<string> inputs
	{
		"ABC",
		"12345",
		"ABCDEFG",
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ",
		"C++isFun!"
	};
	
	bool firstRun = true;
	
	while(true)
	{
		if(firstRun)
		{
			cout << "Welcome to letter pyramid builder. ";
		}
		else
		{
			cout << "\n";
		}
		cout << "Press an option to build." << endl;
		
		for(auto i {0}; i < inputs.size(); i++)
		{
			cout << i + 1 << " - " << inputs.at(i) << endl;
		}
		cout << "\n";
		
		int input = 0;
		cin >> input;
		
		if(input <= 0 || input > inputs.size())
		{
			cout << "Option out of bounds\n" << endl;
			continue;
		}
		
		string s = inputs.at(input - 1);
		drawLetterPyramid(s);
		firstRun = false;
	}
	
	return 0;
}