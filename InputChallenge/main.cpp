#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	int number;
	
	cout << "Enter your favorite number between 1 and 100" << endl;
	cin >> number; 
	
	while(number < 1 || number > 100)
	{
		cout << "Number out of range, please try again" << endl;
		cin >> number; 
	}
	
	cout << "Don't quite like that one" << endl;
	cout << "Tbh, " << number + 1 << " would have been way better" << endl;
	return 0;
}