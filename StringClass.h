#ifndef MYSTR_H
#define MYSTR_H

class myStr {
public:
	int length() const;
	int strCmp(const myStr& compareMe) const;
	int strCmp(const char* compareMe) const;
	bool strCpy(const myStr& copyMe);
	bool strCpy(const char* copyMe);
	int subStr(const char* findMe) const;
	int subStr(const myStr& findMe) const;
	int subStr(const char* findMe, int startingAt) const;
	int subStr(const myStr& findMe, int startingAt) const;
	char at(const unsigned int index) const;
	char* get();
	
	myStr();
	myStr(const myStr& copyMe);
	myStr(const char* copyMe);
	~myStr();

private:
		int   strLen;
		int   dataLen;
		char* data;
};

#endif
