// bitValue
// will give the value of a specified bit for a number
// the value of the bit will be 0 or 1

#include <iostream>

using namespace std;

int main() {
	int value;
	int index;
	int result;
	
	// get the input for the value and the index
	cout << "Enter two integer numbers (each seperated by a space) : ";
	cin >> value >> index;
	
	// shift the binary values to the right
	// it will shift based on the index, this is to get the index we need to
	// index 0 -> as index 0 is 2^0, if the value is even, there is a 0 at
	// the given index while if the value is odd, there is a 1 at the given index
	value = value >> index;
	
	result = value % 2;
	
	cout << "The value of Bit " << index << " is " << result;
	
	return 0;
}