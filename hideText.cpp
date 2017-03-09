// hideText
// "encrypts" or hides a string
// will change the ASCII values of the elements in the string (character array)

#include <iostream>

using namespace std;

int main() {

	char inputText[100];
	int counter = 0;
	int code;
	cout << "Input a word: ";
	cin >> inputText;
	// determine length of word
	while (inputText[counter] != '\0'){
		counter++;
	}
	
	for (int i = 0; i < counter; i++) {
		if (inputText[i] >= 65 && inputText[i] <= 90){
			// capital letter - we need to add 13, but if it passes Z
			// we need to change it back to A
			inputText[i] = inputText[i] + 13;
			if (inputText[i] > 90) {
				inputText[i] = inputText[i] - 26; 
			}
		} 
		else if (inputText[i] >= 97 && inputText[i] <= 122) {
			// we need to change it back to a
			// lowercase letter - we need to add 13, but if it passes z
			inputText[i] = inputText[i] + 13 - 26;
			if (inputText[i] < 97) {
				inputText[i] = inputText[i] + 26;
			}
		}
		else if (inputText[i] >= 48 && inputText[i] <= 57) {
			// number - need to add 5, but if it passes 9 we need to 
			// change it back to 0
			inputText[i] = inputText[i] + 5;
			if (inputText[i] > 57) {
				inputText[i] = inputText[i] - 10;
			}
		}
	}
	
	cout << inputText;
	
	return 0;

}