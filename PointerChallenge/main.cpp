#include <iostream>

using namespace std;

void outputArray(int* pointer, int size)
{
	for(int i {0}; i < size; i++)
	{
		cout << pointer[i] << " ";
	}
	cout << "\n";
}

int* combineArrays(int* array1_ptr, int* array2_ptr, int size)
{
	//Declares the pointer, allocates the array elements
	int *combined {};
	combined = new int [size * size];
	for(int i {0}; i < size; i++)
	{
		for(int j {0}; j < size; j++)
		{
			//maps that alloc to that value
			combined[(i * size) + j] = array1_ptr[i] * array2_ptr[j];
		}
	}
	return combined;
}

//|*(ptr + offset)| and |ptr[offset]| (array-like) have the same result 
//new int[] creates a memory alloc for that array

int main(int argc, char **argv)
{
	int size = 5;
	int array1[] { 1, 2, 3, 4, 5 };
	int array2[] { 10, 20, 30, 40, 50 };
	outputArray(array1, size);
	outputArray(array2, size);
	auto combined_prt = combineArrays(array1, array2, size);
	outputArray(combined_prt, size * size);
}
