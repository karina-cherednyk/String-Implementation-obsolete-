#include "List.h"
#include "String.h"


int countLength(const char* const& p) {
	int cnt(-1);
	while (*(p + (++cnt)));
	return cnt;
}
void fillStr(const char* src, char* targ) {
	while (*targ++ = *src++);
}
void fillStr(char* src, char* targ, int begin, int end, int len) {
	char* source = src;
	char* dest = targ;
	src += begin;
	if (!*src) return;
	for (int i = begin, j = 0; i <= end && j < len; i++, j++) {
		if (!*targ)break;
		*targ++ = *src++;
	}
	*targ = '\0';
}

void replace(String& str,char o, char n) {
	char* ptr = str.p;
	while (*ptr) {
		if (*ptr == o)* ptr = n;
		ptr++;
	}
}
bool isLetter(const char& ch) {
	return ((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z'));
}
String toLowerCase(const String& str) {
	String res = clone(str);
	char* ptr = res.p;
	while (*ptr) {
		if (isLetter(*ptr))* ptr = *ptr | 32;
		ptr++;
	}
	return clone(res);
}
String toUpperCase(const String& str) {
	String res = clone(str);
	char* ptr = res.p;
	while (*ptr) {
		if (isLetter(*ptr))* ptr = *ptr & ~32;
		ptr++;
	}
	return clone(res);
}
String clone(const String& str) {
	return String(str);
}

char* trim(const String* const str) {
	char* ptrBegin = str->p;
	int cntBegin = 0;
	while (*ptrBegin == ' ') { cntBegin++; ptrBegin++; }
	char* ptrEnd = ptrBegin;
	while (*ptrEnd) { ptrEnd++; }
	int cntEnd = 0;
	while (*--ptrEnd == ' ')cntEnd++;
	ptrEnd++;
	char* res = new char[str->len - (cntBegin + cntEnd) + 1];
	char* head = res;
	while (ptrBegin != ptrEnd)* res++ = *ptrBegin++;
	*res = '\0';
	return head;
}

String trim(const String&str) {
	char* ptr = trim(&str);
	return String(ptr);
}
char* copy(const char* const src) {
	const char* ptr = src;
	int length = countLength(src);
	char* targ = new char[length + 1];
	char* head = targ;

	while (*targ++ = *ptr++);
	return head;
}


int compareTo(const String& str1, const String& that) {
	return directComparator.compare(str1, that);
}

ostream& operator<<(ostream& os, const String& str) {
	os << str.p;
	return os;
}


String::String(const char* ptr) {
	len = countLength(ptr);
	if (len > capacity) capacity = 2 * len;
	p = new char[capacity + 1];
	fillStr(ptr, p);
}
String::String(const String* str) {
	len = str->len;
	if (len > capacity) capacity = 2 * len;
	p = new char[capacity + 1];
	fillStr(str->p, p);
}
String::String(char* ptr) {
	len = countLength(ptr);
	capacity = len;
	p = ptr;
}
String::String(char* ptr, int cap) {
	len = countLength(ptr);
	capacity = cap;
	p = ptr;
}
String::~String() {
	delete[] p;
}