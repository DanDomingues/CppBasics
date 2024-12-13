#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum Actions
{ 
	Print,
	Add, 
	Mean, 
	Smallest,
	Largest, 
	Clear, 
	Quit, 
	None 
 };

Actions getInputAction(char input);
void drawInputsDescription();
void runAction(Actions action);
void printValues();
void addInputtedValue();
void outputMean();
void outputMin();
void outputMax();

vector<char> inputs {'P', 'A', 'M', 'S', 'L', 'C', 'Q'};
vector<string> descriptions
{
	"Print numbers",
	"Add a number",
	"Display mean of the numbers",
	"Display the smallest number",
	"Display the largest number",
	"Clear values",
	"Quit"
};

vector<int> values;

int main(int argc, char **argv)
{
	cout << "Welcome to Number Tracker" << endl;
	
	while(true)
	{
		//Welcome screen
		drawInputsDescription();
		
		//Reads for input
		char input;
		cin >> input;
		
		//Validates input
		auto action = getInputAction(input);
		
		if(action != None)
		{
			runAction(action);
		}
		else
		{
			cout << "Input invalid, try again." << endl;
		}
		cout << " " << endl;
	}
	
	return 0;
}

void drawInputsDescription()
{
	for(auto i {0u}; i < inputs.size(); i++)
	{
		cout << inputs.at(i) << " - " << descriptions.at(i) << endl;
	}
	cout << " " << endl;
}

Actions getInputAction(char input)
{
	if(!isalpha(input))
	{
		return None;
	}

	for(auto i {0u}; i < inputs.size(); i++)
	{
		if(toupper(input) != inputs.at(i))
		{
			continue;
		}
		
		return (Actions) i;
	}
	
	return None;
}

void runAction(Actions action)
{
	//Validates collection contents
	bool requireElements = (action != Add) && (action != Quit);
	if(requireElements && values.size() == 0)
	{
		cout << "No values added." << endl;
		return;
	}
	
	//Performs correspondent action
	switch(action)
	{
		case Print:
		printValues();
		break;
		
		case Add:
		addInputtedValue();
		break;
		
		case Mean:
		outputMean();
		break;
		
		case Smallest:
		outputMin();
		break;
		
		case Largest:
		outputMax();
		break;
		
		case Clear:
		values.clear();
		cout << "Numbers cleared" << endl;
		break;
		
		default:
		cout << "Goodbye" << endl;
		break;
	}
}

void printValues()
{
	cout << "Printing numbers..." << endl;
	for(auto value:values)
	{
		cout << value << endl;
	}
}

void addInputtedValue()
{
	cout << "Insert number to be added ";
	int value;
	cin >> value;
	values.push_back(value);
}

void outputMean()
{
	double total {0.0};
	for(auto value:values)
	{
		total += value;
	}
	double mean = total / values.size();
	cout << "Mean: " << mean << endl;
}

void outputMin()
{
	int min = values.at(0);
	for(auto v:values)
	{
		if(v < min)
		{
			min = v;
		}
	}
	cout << "Smallest value: " << min << endl;
}

void outputMax()
{
	int max = values.at(0);
	for(auto v:values)
	{
		if(v > max)
		{
			max = v;
		}
	}
	cout << "Largest value: " << max << endl;
}
