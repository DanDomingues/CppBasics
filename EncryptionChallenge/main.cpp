#include <iostream>
#include <numeric>
#include <string>

using namespace std;

string getEncryptionKey(string reference);
string encrypt(string message, string reference, string encryptor);

int main(int argc, char **argv)
{
	string reference = string(26, ' ');
	//input over t array
	//runs through an iterator, incrementing at every element
	//as we start with 'a' through 26 elements, we can reliably go through the alphabet
	iota(reference.begin(), reference.end(), 'a');
	auto encryptor = getEncryptionKey(reference);

	string message;
	getline(cin, message);
	
	auto encrypted = encrypt(message, reference, encryptor);
	auto decrypted = encrypt(encrypted, encryptor, reference);
		
	cout << encrypted << endl;
	cout << decrypted << endl;
	return 0;
}

string getEncryptionKey(string reference)
{
	string copy = reference;
	string encryptor;
	for(auto i = 0u; i < reference.length(); i++)
	{
		int index = rand() % copy.length();
		encryptor += copy.at(index);
		copy.erase(index, 1);
	}
	return encryptor;
}

string encrypt(string message, string reference, string encryptor)
{
	string encrypted;
	bool is_upper;
	char exchange;
	for(auto c:message)
	{
		if(!isalpha(c))
		{
			encrypted += c;
			continue;
		}

		is_upper = isupper(c);
		c = tolower(c);
		int index = reference.find(c);

		if(index < 0)
		{
			encrypted += c;
			continue;
		}

		exchange = encryptor.at(index);	
		encrypted += is_upper ? toupper(exchange) : exchange;
	}
	return encrypted;
}
