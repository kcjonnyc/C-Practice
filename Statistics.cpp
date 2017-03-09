// Statistics
// Take command line arguments and convert to integer array
// Use functions to fint the maximum, minimum and average

#include <iostream>
#include <stdlib.h>
#include <climits>

using namespace std;

// converts command line arguments into integer array
int convertToIntArray(int argc, char* argv[], int array[]) {
	int c1 = 1; // index 1 of argv is command line arguments
	int c2 = 0;
	double number = 0;
	if (argc > 21) { // there are more than 21 command line arguments
		return -21;
	}
	while (c1 < argc) {
		while (argv[c1][c2] != '\0') {
			// we only accept numbers and +/-
			if ((argv[c1][c2] != '-') && (argv[c1][c2] != '+') && (argv[c1][c2] < 48 || argv[c1][c2] > 57)) {
				return -c1;
			}
			c2++;
		}
		// all the characters of the element are numbers
		// we need to convert them to an integer and store it
		// note** this is somewhat a brute force solution and can be optimized
		number = 0;
		if (argv[c1][0] == '-') {
			for (int i = 1; i < c2; i++) {
				number = (number * 10) + ((int)(argv[c1][i]) - 48);
			}
			number *= -1;
		}
		else if (argv[c1][0] == '+') {
			for (int i = 1; i < c2; i++) {
				number = (number * 10) + ((int)(argv[c1][i]) - 48);
			}
		}
		else {
			for (int i = 0; i < c2; i++) {
				number = (number * 10) + ((int)(argv[c1][i]) - 48);
			}
		}
		if (number < INT_MIN || number > INT_MAX) {
			return -c1;
		}
		array[c1-1] = (int)number;
		c2 = 0;
		c1++;
	}
	return 0;
}

// find maximum value in an array of int
int findMax(int array[], int numElements) {
	int max = array[0];
	for (int i = 0; i < numElements; i++) {
		if (array[i] > max)
			max = array[i];
	}
	return max;
}

// find minumum value in an array of int
int findMin(int array[], int numElements) {
	int min = array[0];
	for (int i = 0; i < numElements; i++) {
		if (array[i] < min)
			min = array[i];
	}
	return min;
}

// find average of values in an array of int
float average(int array[], int numElements) {
	float sum = 0;
	for (int i = 0; i < numElements; i++) {
		sum += array[i];
	}
	return sum / numElements;
}

int main(int argc, char* argv[]) {
	
	// main program to test
	
	if (argc < 2) {
		cerr << "Error: No arguments" << endl;
		return -1;
	}

	int values[20];
	int result = convertToIntArray(argc, argv, values);
	if (result == -21) {
		cerr << "Error: Too many commands";
		return -1;
	}
	else if (result != 0) {
		// there is a argument that is not an integer
		cerr << "Error: Argument " << -result << " is not an integer";
		return -1;
	}
	
	cout << "Maximum: " << findMax(values, argc - 1) << endl;
	cout << "Minimum: " << findMin(values, argc - 1) << endl;
	cout << "Average: " << average(values, argc - 1) << endl;

	return 0;

}