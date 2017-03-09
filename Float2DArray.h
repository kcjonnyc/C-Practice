#ifndef FLOAT2DARRAY_H
#define FLOAT2DARRAY_H
using namespace std;

class Float2DArray 
{
	public:
		float& operator()(int i, int j)const;
		void   operator=(const Float2DArray&);
		
		Float2DArray();
		Float2DArray(int rows, int cols);
		~Float2DArray();
		int maxRowIndex() const;
        int maxColumnIndex() const;
	private:
		int    numRows;
		int    numCols;
		float* data;	
};

bool readTahoeData(char* filename, Float2DArray& lake);

void cleanData(Float2DArray& lake);

float area(Float2DArray& lake);

float volume(Float2DArray& lake);

#endif
