// Float2DArray
// Given a csv file for elevation data of an area around a lake
// we can read in the data and perform various calulations
// this includes: cleaning up the data, calculating area and volume

#include <iostream>
#include <fstream>
#include "Float2DArray.h"

using namespace std;

//operators
float& Float2DArray::operator()(int i, int j) const {
	if (i >= numRows || i < 0 || j >= numCols || j < 0) {
		cerr << "Error: Array out of bounds" << endl;
		float* temp = new float;
		*temp = 0;
		return *temp;
	}
	return *(data + i * numCols + j);
}
void Float2DArray::operator=(const Float2DArray& f) {
	numRows = f.numRows;
	numCols = f.numCols;
	//delete data;
	data = new float[f.numRows*f.numCols];
	for (int i = 0; i < f.numRows*f.numCols; i++) {
		data[i] = f.data[i];
	}
}
	
// constructors
Float2DArray::Float2DArray() {
	numRows = 0;
	numCols = 0;
}
Float2DArray::Float2DArray(int rows, int cols) {
	data = new float[rows*cols];
	numRows = rows;
	numCols = cols;
}
// destructor
Float2DArray::~Float2DArray() {
	if (data != NULL) {
		//delete data;
	}
	data = NULL;
	numRows = -1;
	numCols = -1;
}

int Float2DArray::maxRowIndex() const {
	return numRows;
}
int Float2DArray::maxColumnIndex() const {
	return numCols;
}

// global variables storing size
int numRows = 0;
int numColumns = 0;

// read in lake tahoe data
bool readTahoeData(char* filename, Float2DArray& lake) {
	float extracted;
	int row = 0;
	int column = 0;
	// attempt to open file
	ifstream inFile;
	inFile.open (filename);
	if (!inFile.is_open()) {
		cerr << "Error: Could not open file" << endl;
		return false;
	}
	// read in data from csv file
	// the first two items in the csv file are the numRows and numColumns
	inFile >> extracted;
	numRows = extracted;
	inFile >> extracted;
	numColumns = extracted;
	cout << numRows << endl;
	cout << numColumns << endl;
	// read in actual data points into array
	while (!inFile.eof() && row < numRows) {
		while (!inFile.eof() && column < numColumns) {
			inFile >> extracted;
			while (inFile.peek() == ' ' || inFile.peek() == ',') {
				inFile.get(); // get rid of comma
			}
			//cout << extracted << endl;
			lake(row, column) = extracted;
			column++; 
		}
		column = 0;
		row++;
	}
	inFile.close();
	return true;
}

// clean data adjusting the outliers
void cleanData (Float2DArray& lake) {
	// we do not determine outliers for first and last rows and columns
	// given size of 420, 210
	// first values to check from 1,1 -> 1,208
	// last values to check from 418,1 -> 418,208
	// first obtain averages off all this data (from 8 neighbours)
	float averages[numRows][numColumns]; // initialized to 0
	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < numColumns; j++) {
			averages[i][j] = 0;
		}
	}
	int row = 1;
	int column = 1;
	int difference = 0;
	while (row < numRows - 1) {
		while (column < numColumns - 1) {
			averages[row][column] += lake(row-1, column-1);
			averages[row][column] += lake(row-1, column);
			averages[row][column] += lake(row-1, column+1);
			averages[row][column] += lake(row, column-1);
			averages[row][column] += lake(row, column+1);
			averages[row][column] += lake(row+1, column-1);
			averages[row][column] += lake(row+1, column);
			averages[row][column] += lake(row+1, column+1);
			averages[row][column] /= 8;
			averages[row][column] *= 10; // rounding
			averages[row][column] += 0.5;
			averages[row][column] = (int)averages[row][column];
			averages[row][column] /= 10;
			column++;
		}
		column = 1;
		row++;
	} // we now have all averaged data
	// now replace the outliers
	row = 1;
	column = 1;
	while (row < numRows - 1) {
		while (column < numColumns - 1) {
			difference = lake(row, column) - averages[row][column];
			if (difference < 0) {
				difference *= -1; // need to take absolute value
			}
			if (difference > 100) {
				lake(row, column) = averages[row][column];
			}
			column++;
		}
		column = 1;
		row++;
	} // we now have all data cleaned up
}

// determine the area of the lake
float area(Float2DArray& lake) {
	// if elevation is negative it is part of the lake
	// each piece of data is 100 x 100m so add up number of negative cells
	// and multiply by 10000
	int counter = 0;
	float a = 0;
	for (int row = 0; row < numRows; row++) {
		for (int column = 0; column < numColumns; column++) {
			if (lake(row, column) < 0) {
				counter++;
			}
		}
	}
 	a = counter * 10000.0;
	return a;
}

// determine the volume of the lake
float volume(Float2DArray& lake) {
	float vol = 0;
	for (int row = 0; row <numRows; row++) {
		for (int column = 0; column < numColumns; column++) {
			if (lake(row, column) < 0) { // elevation is negative
				vol += (-10000.0 * lake(row, column));
			}
		}
	}
	return vol;
}