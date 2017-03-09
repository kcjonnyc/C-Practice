// factorial
// will display the factorial of a number

#include <iostream>
#include <stdint.h>

using namespace std;

int main() {

	int value;
	uint64_t output = 1;
	
	// obtain number from user
	cout << "Enter a number: ";
	cin >> value;
	
	// we can only calculate the factorial within a certain bound here
	if (value < 0 || value > 20){
		cerr << "Error: Invalid Input";
		return -1;
	}
	else if (value != 0) {
		// use a for loop to calculate the factorial
		for (int x = 1; x <= value; x++) {
			output = output * x;
		}
	}
	
	cout << "It's factorial is: " << output << endl;

	return 0;
}