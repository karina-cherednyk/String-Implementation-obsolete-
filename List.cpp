#include "List.h"
#include "Node.h"
#include <cassert>

bool List::isEmpty() {
	return n == 0;
}
bool isEmpty(const List& l) {
	return l.n == 0;
}

void List::addNode(Node* h) {
	n++;
	if (head == NULL) head = h;
	else head->addNext(h);
}
void List::add(const char* p) {
	n++;
	String* s = new String(p);
	Node* newNode = new Node(s);
	if (head == NULL) head = newNode;
	else head->addNext(newNode);
}
void List::add(char* p) {
	n++;
	String* s = new String(p);
	Node* newNode = new Node(s);
	if (head == NULL) head = newNode;
	else head->addNext(newNode);
}
void List::add(String& s) {
	n++;
	Node* newNode = new Node(s.p);
	if (head == NULL) head = newNode;
	else head->addNext(newNode);
}

Node* getMiddleNode(Node* node) {
	Node* slow = node;
	Node* fast = node;
	while (slow->hasNext && fast->hasNext && fast->next->hasNext) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

Node* merge(Node* a, Node* b, const StringComparator& comp) {
	Node* head = new Node();
	Node* c = head;
	bool bEnd=false, aEnd=false;
	while (!bEnd && !aEnd) {
		int cmp = comp.compare(a->str,b->str);
		if (cmp <= 0) {
			c->setNext(a);
			if (a->hasNext) a = a->next;
			else aEnd = true;
		}
		else {
			c->setNext(b);
			if (b->hasNext) b = b->next;
			else bEnd = true;
		}
		c = c->next;
		
	}
	while(!aEnd) {
		c->setNext(a);
		if (a->hasNext) a = a->next;
		else aEnd = true;
		c = c->next;
	}
	while (!bEnd) {
		c->setNext(b);
		if (b->hasNext) b = b->next;
		else bEnd = true;
		c = c->next;
	}
	return head->next;
}
Node* sort(Node* node, const StringComparator& comp) {
	if (!node->hasNext) return node;
	Node* middle = getMiddleNode(node);
	assert(middle->hasNext);
	Node* middle1 = middle->next;
	middle->hasNext = false;
	middle->next = NULL;
	Node* left =   sort(node, comp);
	Node* right =  sort(middle1, comp);
	Node* head = merge(left, middle1, comp);
	return head;
}
void List::sort(const StringComparator& comp) {
	head = ::sort(head, comp);
}

ostream& operator<<(ostream& os, const List& list) {
	Node* node = list.head;
	for (int i = 0; i < list.n; i++) {
		os << *node->str << endl;
		if (node->hasNext)node = node->next;
	}
	return os;
}

void Node::setNext(Node* nextNode) {
	next = nextNode;
	hasNext = true;
}
void Node::addNext(Node* nextNode) {
	if (hasNext) next->addNext(nextNode);
	else setNext(nextNode);
}
String& List::operator[](int pos) const {
	modNeg(pos, n);
	if (pos >= n) throw indexError;
	Node* node = head;
	for (int i = 1; i <= pos; i++) {
		node = node->next;
	}
	return *(node->str);
}
void sort(List& list, const StringComparator& comp) {
	list.head = sort(list.head,comp);
}
char* List::toString() {
	int cntChar(0);
	char* temp;
	Node* node = head;
	for (int i = 0; i < n; i++) {
		temp = node->str->p;
		if (node->hasNext)node = node->next;
		while (*temp++)cntChar++;
		cntChar++;
	}
	char* res = new char(cntChar);
	char* wordHead = res;

	node = head;
	for (int i = 0; i < n; i++) {
		temp = node->str->p;
		if (node->hasNext)node = node->next;
		while (*temp)* res++ = *temp++;
		if (i != n - 1)* res++ = ' ';
		else *res = '\0';
	}
	return wordHead;
}
char* toString(const List& l) {
	int cntChar(0);
	char* temp;
	Node* node = l.head;
	for (int i = 0; i < l.n; i++) {
		temp = node->str->p;
		if (node->hasNext)node = node->next;
		while (*temp++)cntChar++;
		cntChar++;
	}
	char* res = new char(cntChar);
	char* wordHead = res;

	node = l.head;
	for (int i = 0; i < l.n; i++) {
		temp = node->str->p;
		if (node->hasNext)node = node->next;
		while (*temp)* res++ = *temp++;
		if (i != l.n - 1)* res++ = ' ';
		else *res = '\0';
	}
	return wordHead;
}
