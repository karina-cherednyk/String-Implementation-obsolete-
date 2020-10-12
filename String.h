#pragma once 
#include <iostream>
#include <cassert>
using namespace std;

const unsigned int indexError = 111;



struct List;

struct String {
	char* p=NULL;
	size_t len=0;
	size_t capacity = 16;
	String(const char* );
	String(const String*);
	String(char*);
	String() {}
	String(char*, int capacity);
	~String();

};


void replace(String& ,const char, const char);
void modify( String& ,char* p);
String toLowerCase(const String&);
String toUpperCase(const String&);
String clone(const String&);
String trim(const String&);

int compareTo(const String&);


String& operator+=(const String&, const String&);
const char& get(const String&, int);
void set(String&, int, const char);
const unsigned int count(const String&, const String&);
const unsigned int getFirst(const String&, const String&);
const unsigned int getFirst(const String&, const String& word, int pos);
String substring(const String&, const String& begin, const String& end);
String substring(const String&, int begin, int end);
const String replace(const String&, const String& prev, const String& next);
const unsigned int getPos(const String&, const int begin, const char* const& delimeters, size_t n);
List split(const String&, const char* const& delimeters, size_t n);
void checkIndices(const String&, int& begin, int& end);

String remove(const String&, const int begin, const int end);
String remove(const String&, const String& begin, const String& end);


bool operator==(const String&, const String& str);
bool operator>(const String&, const String& str);
bool operator>=(const String &, const String& str);
bool operator<(const String&, const String& str);
bool operator<=(const String&, const String& str);

String operator*(const String&, const int x);



ostream& operator<<(ostream& os, const String& str);
istream& operator>>(istream& os, String& str);
bool operator==(const String& s1, const String& s2);

int countLength(const char* const& p);
void fillStr(const char* src, char* targ);
void fillStr(char* src, char* targ, int begin, int end, int len);
char* copy(const char* const src);



struct StringComparator {
	const int (*compare)(const String& s1, const String& s2);
};

const int compareDirect(const String& s1, const String& s2);
const int compareReverse(const String& s1, const String& s2);
const StringComparator directComparator{ compareDirect };
const StringComparator reverseComparator{ compareReverse };

inline void modNeg(int& i, int mod) {
	while (i < 0) i += mod;
}