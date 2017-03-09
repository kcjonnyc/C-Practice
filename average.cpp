// average
// average program that rejects the highest and lowest input

#include <iostream>

using namespace std;

int main() {
	
	int sum = 0; 
	int input;
	int lowest; // lowest and highest inputs
	int highest;
	int counter = 0;
	
	// take in inputs until we get a 0
	do {
		cin >> input;
		if (counter == 0) { // for first input
			lowest = input;
			highest = input;
		}
		if (input != 0) { // determine the new highest and lowest values
			sum += input;
			if (input > highest)
				highest = input;
			else if (input < lowest) 
				lowest = input;
			counter++;
		}
	} while (input != 0);
	
	cout << "Rejected Max: " << highest << endl;
	cout << "Rejected Min: " << lowest << endl;
	// calculate average based on the sum excluding the highest and lowest values
	double average = (double)(sum - highest - lowest) / (double)(counter - 2);
	cout << (sum - highest - lowest);
	cout << (counter - 2);
	cout << "Average of other inputs: " << average;
	
	return 0;
	
}