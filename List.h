#pragma once
#include <iostream>
#include "String.h"
#include "Node.h"
using namespace std;




struct List {
	Node* head = 0;
	int n = 0;
	List(Node* h, const int len) :head(h), n(len) {};
	List() {};
	void addNode(Node* h);
	void add(const char* p);
	void add(char* p);
	void add(String& str);
	~List() {
		delete head;
	}

	bool isEmpty();
	char* toString();
	void sort(const StringComparator& comp = directComparator);
	String& operator[](int pos) const;
};


ostream& operator<<(ostream& os, const List& list);

void sort(List& list , const StringComparator& comp = directComparator);
char* toString(const List & l);