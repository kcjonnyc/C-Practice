// robustAdd
// a program to add two numbers while checking for various errors
// it will check for integer overflow and refuse to add numbers with letters
// for example, you cannot add 123 + 123abc

#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

int main() {
	
	int number;
	int number2;
	cout << "Enter two integers to add: ";
	cin >> number >> number2;
	
	// if cin failed, we know the input definitely isn't an integer
	if (cin.fail()) {
		// this will actually catch all the errors in the first number
		// if there were letters, they will be the first things the system
		// tries to write to number2
		cerr << "Error: Invalid input. Non-integer detected.";
		exit (-1);
	}
	else {
		char next = cin.get();
		if (next == ' ' || next == '\n' || next == '\t') {
			// we will need to check either sum > INT_MIN or sum < INT_MAX
			// if (number == 0 || number2 == 0) there we do not need to worry about the sum
			if (number < 0) {
				// we need to worry about the lower bound - the sum cannot exceed the upper bound
				if ((INT_MIN - number) <= number2) {
					// (INT_MIN - number) is the smallest value number2 can be for the sum to still be valid
					int sum = number + number2;
					cout << "Sum of two numbers is: " << sum << endl;
				}
				else {
					cerr << "Error: Summed value out of the signed int range.";
					exit (-1);
				}
			}
			else { // number >= 0
				// we need to worry about the upper bound - the sum cannot exceed the lower bound
				if ((INT_MAX - number) >= number2) {
					// if this is true, there is space to add both numbers
					int sum = number + number2;
					cout << "Sum of two numbers is: " << sum << endl;
				}
				else {
					cerr << "Error: Summed value out of the signed int range.";
					exit (-1);
				}	
			}
		}
		else {
			// this will catch any errors in the second input
			cerr << "Error: Invalid input. Non-integer detected.";
			exit (-1);
		}
	}
	
	return 0;
}