#pragma once
#include "String.h"

struct Node {
	String* str = 0;
	Node* next = 0;
	Node(String s)  {
		str = new String(s);
	}
	Node(String* s) :str(s) {}
	Node(char* p) :str(new String(p)) {}
	Node(const char* p) :str(new String(p)) {}
	Node() {}
	~Node() {
		delete str;
		if (hasNext) delete next;
	}
	bool hasNext = false;
	void setNext(Node* nextNode);
	void addNext(Node* nextNode);
	const int len() {
		return str->len;
	}
};