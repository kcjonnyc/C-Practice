// ArrayOfStruct
// Perform various operations to Person structure defined in header file

#include <iostream>
#include "ArrayOfStruct.h"

using namespace std;

// display names given the number of people and array of people
void displayNames (int numPeople, Person people[]) {
	for (int i = 0; i < numPeople; i++) {
		cout << people[i].firstName << " " << people[i].lastName << " " << people[i].age << endl;
	}
	cout << endl;
}

// string compare function
// returns 1 if first string is shorter or first different char in str1 comes after str2
// returns -1 if second string is shorter or first different char in str1 comes before str2
int stringCmp (char str1[], char str2[]) {
	int i = 0;
	// we want to compare each character until will reach the end of one or they are not equal
	while (str1[i] != '\0' && str1[i] == str2[i]) {
		i++;
	}
	char letter1 = str1[i];
	char letter2 = str2[i];
	if (letter1 >= 65 && letter1 <= 90) {
		letter1 += 32;
	}
	if (letter2 >= 65 && letter2 <= 90) {
		letter2 += 32;
	}
	if (letter1 == '\0' && letter2 == '\0') {
		// if we reached the end of both arrays they are the same
		return 0;
	}
	else if (letter1 == '\0') { // first str is shorter
		return 1;
	}
	else if (letter2 == '\0') { // second str is shorter
		return -1;
	}
	else { // str1[i] != str2[i]
		// we encountered a index where the characters are not the same
		// if character in str one is not the same as one in str two, we can stop comparing
		if (letter1 > letter2) { // different char in str 1 comes after str 2
			return -1;
		}
		else if (letter1 < letter2) { // different char in str 1 comes before str 2
			return 1;
		}
	}
}

// function to swap two people structs
void personSwap (Person &people1, Person &people2) {
	Person temp;
	temp = people1;
	people1 = people2;
	people2 = temp;
}

// bubble sort algorithm to sort names
// sort alphabetically by last name then first name, then age (if same name)
void bubbleSort (int numPeople, Person people[]) {
	bool swap = false;
	int temp = 0;
	do {
		swap = false;
		for (int i = 0; i < numPeople -1; i++) {
			// compare last names
			if (stringCmp(people[i].lastName, people[i+1].lastName) == -1) {
				// second name is supposed to come first - swap required
				swap = true;
			}
			else if (stringCmp(people[i].lastName, people[i+1].lastName) == 0) {
				// last name is the same, need to check first name
				if (stringCmp(people[i].firstName, people[i+1].firstName) == -1) {
					// second first name is supposed to come first - swap required
					swap = true;
				}
				else if (stringCmp(people[i].firstName, people[i+1].firstName) == 0) {
					// last name is the same, need to check age
					if (people[i].age > people[i+1].age) {
						// age of first greater than age on second, swap required
						swap = true;
					}
				}
			}
			if (swap == true) {
				personSwap(people[i], people[i+1]);
			}
		}
	} while (swap == true);
}