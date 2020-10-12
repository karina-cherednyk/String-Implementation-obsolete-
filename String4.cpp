#include "String.h"
#include "List.h"



void resize(String& str) {
	char* ptr = new char[str.capacity + 1];
	char* ptr2 = ptr;
	while (*ptr2++ = *str.p++);
	delete[] str.p;
	str.p = ptr;
}
String& operator+=(String& str1, const String& str) {
	int l = str.len;
	if (str1.len + l > str1.capacity) {
		str1.capacity = (str1.len + l) * 2;
		resize(str1);
	}
	for (int i = 0; i < l; i++) str1.p[str1.len + i] = str.p[i];
	str1.p[str1.len + l] = '\0';
	str1.len += l;
	return str1;
}

void set(String& str, int pos, const char ch) {
	modNeg(pos, str.len);
	str.p[pos] = ch;
}
const unsigned int count(const String& str,const String& word) {
	int l = word.len;
	unsigned int count = 0;
	for (int i = 0; i < str.len - l + 1; i++) {
		if (str.p[i] != word.p[0]) continue;
		bool found = true;
		for (int j = 1; j < l; j++) {
			if (str.p[i + j] != word.p[j]) {
				found = false;
				break;
			}
		}
		if (found)count++;
	}
	return count;
}
const unsigned int getFirst(const String& str, const String& word) {
	int l = word.len;
	for (int i = 0; i < str.len - l + 1; i++) {
		if (str.p[i] != word.p[0]) continue;
		bool found = true;
		for (int j = 1; (j < l); j++) {
			if (str.p[i + j] != word.p[j]) {
				found = false;
				break;
			}
		}
		if (found) return i;
	}
	return -1;
}
const unsigned int getFirst(const String& str, const String& word, int pos) {
	int l = word.len;
	for (int i = pos; i < str.len - l + 1; i++) {
		if (str.p[i] != word.p[0]) continue;
		bool found = true;
		for (int j = 1; (j < l); j++) {
			if (str.p[i+j] != word.p[j]) {
				found = false;
				break;
			}
		}
		if (found) return i;
	}
	return -1;
}
String substring(const String& str, const String& begin, const String& end) {
	int firstIndex = getFirst(str,begin);
	int lastIndex = getFirst(str,end, firstIndex) + end.len - 1;
	if (firstIndex == -1 || lastIndex == -1) throw indexError;
	return substring(str,firstIndex, lastIndex);
}
void checkIndices(const String& str, int& begin, int& end) {
	if (end < 0) modNeg(end, str.len);
	if (begin < 0) modNeg(begin, str.len);
	if(end>=str.len || begin>=str.len)throw indexError;
	if (end < begin)throw indexError;
}
String substring(const String& str, int begin, int end) {
	checkIndices(str, begin, end);

	char* res = new char[(end - begin) + 2];
	int j = 0;
	for (int i = begin; i <= end; i++, j++) res[j] = str.p[i];
	res[end - begin + 1] = '\0';
	return res;
}
String remove(const String& str, int begin, int end) {
	checkIndices(str,begin, end);
	int l = str.len - (end - begin + 1);
	char* ptr = new char[l + 1];

	for (int i = 0, j = 0; i < str.len; i++)
		if (i<begin || i>end) ptr[j++] = str.p[i];

	ptr[l] = '\0';
	return ptr;
}
String remove(const String& str, const String& begin, const String& end) {
	int firstIndex = getFirst(str,begin);
	int lastIndex = getFirst(str,end) + end.len - 1;

	return remove(str,firstIndex, lastIndex);
}

const String replace(const String& str,const String& prev, const String& next) {
	unsigned int pr_n = prev.len;
	unsigned int n_n = next.len;

	unsigned int c = count(str,prev);
	int dif = (n_n - pr_n) * c;
	char* res = new char[str.len + dif + 1];
	unsigned int pos = 0;

	for (int i = 0; i < str.len; i++) {
		res[pos++] = str.p[i];
		if (str.p[i] != prev.p[0]) continue;
		if (i >= str.len - pr_n + 1) continue;
		bool found = true;
		for (unsigned int j = 1; j < pr_n; j++) {
			if (str.p[i + j] != prev.p[j]) {
				found = false;
				break;
			}
		}
		if (found) {
			pos--;
			for (unsigned int j = 0; j < n_n; j++) res[pos++] = next.p[j];
			i += pr_n - 1;
		}
	}
	res[str.len + dif] = '\0';
	return res;
}
bool isIn(char ch, const char* const& delimeters, size_t n) {
	for (unsigned int i = 0; i < n; i++)
		if (ch == delimeters[i]) return true;
	return false;
}
const unsigned int getPos(const String& str, const int begin, const char* const& delimeters, size_t n) {
	int pos = begin;
	while (pos < str.len && !isIn(str.p[pos], delimeters, n))pos++;
	return pos;
}
List split(const String& str, const char* const& delimeters, size_t n) {
	int len = str.len;
	const char* p = str.p;
	int del;
	char* word;
	int i = 0;
	Node* headNode = 0;
	int cnt = 0;
	Node* node = 0;
	bool first = true;
	while (i < len) {
		del = getPos(str,i, delimeters, n);
		word = new char[del - i + 1];
		for (int j = 0; j < del - i; j++) word[j] = str.p[i + j];
		word[del - i] = '\0';
		if (first) {
			headNode = node = new Node(word);
			first = false;
			cnt++;
		}
		else {
			node->setNext(new Node(word));
			node = node->next;
			cnt++;
		}
		i = del + 1;
	}
	return List(headNode, cnt);
}


bool operator==(const String& str1,const String& str) {
	return !directComparator.compare(str1, str);
}

String operator*(const String& str,const int x) {
	if (x < 0) throw indexError;
	int len = str.len;
	const char* p = str.p;
	int l = len * x;
	int capacity = 2 * l;
	char* head = new char[capacity + 1];
	char* ptr = head;

	for (unsigned int i = 0; i < len; i++) {
		for (unsigned int j = 0; j < x; j++) ptr[i + len * j] = p[i];
	}
	ptr[l] = '\0';
	return String(head, capacity);
}
istream& operator>>(istream& is, String& str) {
	char ptr[50];
	
	cin.getline(ptr, 50);
	int i = -1;
	while (*(ptr + (++i)));
	char* p = new char[i+1];
	for (int j = 0; j <= i; j++) {
		p[j] = ptr[j];
	}
	
	modify(str,p);
	return is;
}

void modify(String& str1,char* ptr) {
	str1.len = countLength(ptr);
	str1.p = ptr;
}

bool operator>(const String& str1,const String& str) {
	return directComparator.compare(str1, str) > 0;
}
bool operator>=(const String& str1, const String& str) {
	return directComparator.compare(str1, str) >= 0;
}
bool operator<(const String& str1, const String& str) {
	return directComparator.compare(str1, str) < 0;
}
bool operator<=(const String& str1, const String& str) {
	return directComparator.compare(str1, str) <= 0;
}