#include <iostream>
#include <string>

using namespace std;

const double smallRoomPrice {25.0};
const double largeRoomPrice {35.0};
const double serviceTax {0.06};
const int estValidity {30};

int main(int argc, char **argv)
{
	int smallRooms {0};
	int largeRooms {0};

	//Input handling
	cout << "Hello, welcome to Frank's Carpet Cleaning Service." << endl;
	cout << "\nHow many small rooms would you like cleaned? ";
	cin >> smallRooms;
	cout << "How many large rooms would you like cleaned? ";
	cin >> largeRooms;
	
	//Bill calculations
	double smallRoomsValue = smallRooms * smallRoomPrice;
	double largeRoomsValue = largeRooms * largeRoomPrice;
	double total = smallRoomsValue + largeRoomsValue;
	double tax = total * serviceTax;
	
	//Outputting
	cout << "Price per small room: $" << smallRoomPrice << endl;
	cout << "Price per large room: $" << largeRoomPrice << endl;
	cout << "Total: $" << total << endl;
	cout << "Tax: $" << tax << endl;
	cout << string(50, '=') << endl;
	cout << "Total estimate: $" << total + tax << endl;
	cout << "This estimate is valid for " << estValidity << " days" << endl;

	return 0;
}
