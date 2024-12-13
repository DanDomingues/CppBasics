#include <iostream>
#include <vector>

using namespace std;

vector<int> getCoinValues(int centsAmount);
void outputCoins(vector<int> coinValues);

vector<int> coinDefinitions 
{
	100,
	25,
	10,
	5,
	1
};

vector<string> coinNames 
{ 
	"dollar", 
	"quarter", 
	"dime", 
	"nickel", 
	"pennie"
};

int main(int argc, char **argv)
{
	//Gets input
	int cents;
	cout << "Enter an amount in cents: ";
	cin >> cents;
	
	//Converts into coin amount
	auto coinValues = getCoinValues(cents);
	
	//Outputs coins to the console
	outputCoins(coinValues);
	return 0;
}

vector<int> getCoinValues(int centsAmount)
{
	vector<int> coinValues;
	int value;
	for(auto def:coinDefinitions)
	{
		value = centsAmount / def;
		centsAmount %= def;
		coinValues.push_back(value);
	}
	return coinValues;
}

void outputCoins(vector<int> coinValues)
{
	for(auto i = 0u; i < coinValues.size(); i++)
	{
		cout << coinNames.at(i) << "s : " << coinValues.at(i) << endl;
	}
}
