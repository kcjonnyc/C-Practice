// reverse
// algorithm to reverse a string of characters

#include <iostream>

using namespace std;

int main () {

	char input[21];
	char reverse[21];
	int counter = 0;
	int length;
	
	cout << "Enter a word: ";
	cin >> input;
	
	// determine length of input
	while (input[counter] != '\0') {
		counter++;
	}
	cout << "Counter:" << counter;
	length = counter;
	
	// using a for loop, determine the first word
	for (int i = 0; i < length; i++) {
		counter--;
		reverse[i] = input[counter];
	}

	reverse[length] = '\0';
	cout << "Reversed word: " << reverse;
	
	return 0;

}