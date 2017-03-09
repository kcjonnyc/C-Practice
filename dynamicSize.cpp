// dynamicSize
// example of dynamic memory allocation
// take in a series of numbers and create a new array of double the size when
// the array fills up

#include <iostream>

using namespace std;

int main() {

	int input;
	int count = 0;
	int size = 4   // always holds current size of array

	// create an initial array of 4 elements
	int* array = new int[size];
	
	cout << "Please input numbers: ";
	do {
		if (count == size) { // need more storage space
			size *= 2;
			int* array2 = new int[size]; // create new array of double size
			for (int i = 0; i < size/2; i++) { // need to copy the elements over
				array2[i] = array[i];
			}
			array = array2;
		}
		cin >> input; // obtain the next value
		array[count] = input;
		count++;
	} while (input != 0);
	
	count = 0;
	// print out the list
	cout << "Your list was: ";
	while (myArray[count] != 0) {
		cout << myArray[count] << " ";
		count++;
	}

	return 0;

}