// StringClass
// This is a string class with it's functionallity described in the header file.
// Class allows a user to create String objects and perform various operations with them.
// This includes finding the length, comparing different string objects, obtaining 
// a substring, copying a string and getting a character at a particular index

#include <iostream>
#include "StringClass.h"

using namespace std;

// length function returns the length of the string
int myStr::length() const{
	return strLen;
}

// string compare functions
int myStr::strCmp(const myStr& compareMe) const { // const as we are not changing any variables
	int count = 0;
	if (data[count] == '\0' || compareMe.data[count] == '\0') {
		return -1;
	}
	while (data[count] != '\0' && data[count] == compareMe.data[count]) {
		count++;
	} // while loop will end when one string hits null terminator or difference is found
	if (data[count] == '\0' && compareMe.data[count] == '\0') // both strings need to equal null terminator at end
		return 0;
	else if (data[count] == '\0') // string1 is shorter
		return 1;
	else if (compareMe.data[count] == '\0') // string2 is shorter
		return -1;
	else {
		if (data[count] > compareMe.data[count])
			return -1;
		else
			return 1;
	}
}
int myStr::strCmp(const char* compareMe) const {
	int count = 0;
	if (data[count] == '\0' || compareMe[count] == '\0') {
		return -1;
	}
	while (data[count] != '\0' && data[count] == compareMe[count]) {
		count++;
	} // while loop will end when one string hits null terminator or difference is found
	if (data[count] == '\0' && compareMe[count] == '\0') // both strings need to equal null terminator at end
		return 0;
	else if (data[count] == '\0') // string1 is shorter
		return 1;
	else if (compareMe[count] == '\0') // string2 is shorter
		return -1;
	else {
		if (data[count] > compareMe[count])
			return -1;
		else
			return 1;
	}
}
	
// string copy functions
bool myStr::strCpy(const myStr& copyMe) {
	if (copyMe.strLen + 1 > dataLen) { 
		// we do not have enough space so we need to create a new array
		//delete data;
		data = new char[copyMe.dataLen];
		dataLen = copyMe.dataLen; // data length changes
	}
	// we have enough space for the string and the null terminator
	// proceed to copy the string over
	for (int i = 0; i < copyMe.strLen; i++) {
		data[i] = copyMe.data[i];
	}
	data[copyMe.strLen] = '\0';
	strLen = copyMe.strLen; // string length changes
	return true;
}
bool myStr::strCpy(const char* copyMe) {
	// determine string length
	int count = 0;
	while (copyMe[count] != '\0') {
		count++;
	} // count is now the string length
	if (count + 1 > dataLen) { 
		// we do not have enough space so we need to create a new array
		//delete data;
		data = new char[count + 1];
		dataLen = count + 1; // data length changes
	}
	// we have enough space for the string and the null terminator
	// proceed to copy the string over
	for (int i = 0; i < count; i++) {
		data[i] = copyMe[i];
	}
	data[count] = '\0';
	strLen = count; // string length changes
	return true;
}
	
// substring fuctions
int myStr::subStr(const char* findMe) const {
	int count = 0;
	int count2 = 0;
	while (data[count] != '\0') {
		while (data[count + count2] == findMe[count2]) {
			if (findMe[count2 + 1] == '\0') { // substring exists
			 // we check if fineMe[count2+1] as we know everything before null
				 // terminator is the same but data will not be null terminated in the middle
				return count;
			}
			count2++;
		}
		count2 = 0;
		count++;
	}
	return -1;
}
int myStr::subStr(const myStr& findMe) const {
	int count = 0;
	int count2 = 0;
	while (data[count] != '\0') {
		while (data[count + count2] == findMe.data[count2]) {
			if (findMe.data[count2 + 1] == '\0') { 
				return count;
			}
			count2++;
		}
		count2 = 0;
		count++;
	}
	return -1;
}
int myStr::subStr(const char* findMe, int startingAt) const {
	int count = startingAt;
	int count2 = 0;
	while (data[count] != '\0') {
		while (data[count + count2] == findMe[count2]) {
			if (findMe[count2 + 1] == '\0') { 
				return count;
			}
			count2++;
		}
		count2 = 0;
		count++;
	}
	return -1;
}
int myStr::subStr(const myStr& findMe, int startingAt) const {
	int count = startingAt;
	int count2 = 0;
	while (data[count] != '\0') {
		while (data[count + count2] == findMe.data[count2]) {
			if (findMe.data[count2 + 1] == '\0') { 
				return count;
			}
			count2++;
		}
		count2 = 0;
		count++;
	}
	return -1;
}
	
// char at function 
char myStr::at(const unsigned int index) const {
	if (index > strLen || index < 0) {
		return 0;
	}
	else {
		return data[index];
	}
}

/*// get function to return the string itself
	char* myStr::get() {
		// create a copy of the string as a char pointer and return it
		char* string = new char[dataLen];
		for (int i = 0; i < strLen; i++) {
			string[i] = data[i];
		}
		string[strLen] = '\0';
		return string;
	}*/
	
// constructors
myStr::myStr() { 
	// default constructor
	data = new char[1];
	data[0] = '\0';
	strLen = 0;
	dataLen = 1;
}
myStr::myStr(const myStr& copyMe) {
	// takes a myStr object and creates a new string that is a copy of the passed parameter
	// although the three parameters are private as members of the class we still have access 
	// to private data and methods from other instances
	strLen = copyMe.strLen;
	dataLen = copyMe.dataLen;
	data = new char[dataLen];
	for (int i = 0; i < strLen; i++) {
		data[i] = copyMe.data[i];
	}
	data[strLen] = '\0'; 
}
myStr::myStr(const char* copyMe) {
	// takes a char* string and creates string object
	int count = 0;
	while (copyMe[count] != '\0') {
		count++;
	}
	strLen = count;
	dataLen = count + 1;
	data = new char[dataLen]; // create an array with enough space for all letters and null terminator
	for (int i = 0; i < strLen; i++) {
		data[i] = copyMe[i];
	}
	data[strLen] = '\0'; // last character in char array needs to be null terminated
}
	
// destructor
myStr::~myStr() {
	//delete data;
	strLen = -1;
	dataLen = -1;
}



