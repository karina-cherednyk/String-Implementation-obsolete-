#include <iostream>
#include <cassert>
#include "List.h"
using namespace std;

int getInt() {
	char num[5];
	cin.getline(num,5);
	return atoi(num);
}

int printCommands() {
	cout << "--------------------------------------------------------" << endl;
	cout << "0 - Create and use new string" << endl;
	cout << "1 - Substring from index to index" << endl;
	cout << "2 - Substring from string to string" << endl;
	cout << "3 - Count occurences" << endl;
	cout << "4 - Get index of first occurence of string" << endl;
	cout << "5 - Replace one string by another" << endl;
	cout << "6 - Split string into list of words by delimeters" << endl;
	cout << "7 - Remove context from index to index" << endl;
	cout << "8 - Remove context from string to string(first occurence)" << endl;
	cout << "9 - Compare strings" << endl;
	cout << "10- Get char at position" << endl;
	cout << "11- Repeat string n times" << endl;
	cout << "12- Create and use new list" << endl;
	cout << "13- Sort list in direct order" << endl;
	cout << "14- Sort list in reverse order" << endl;
	cout << "15- Get string in position i in list" << endl;
	cout << "16- Exit" << endl;
	cout << "---------------------------------------------------------" << endl;
	return  getInt();
}
int main() {
	

	int hh = 0;
	cout << "String class" << endl;
	
	cout << "Enter string: ";
	String str;
	cin >> str;

	String s, es, bs, from, to, o;
	int b, e, n, i;
	char* m=0;
	char* ch=0;
	char* del = 0;
	int eee =0;
	List l;
	int answ = printCommands();

	 int MM = 0;
	while (answ != 16) {
		try{
		cout << "String: " << str << endl;
		if (!l.isEmpty()) {
			cout << "List: " << endl;
			cout << l << endl; 
		}
	
		switch (answ) {
		case 0:
			cout << "New string:";
			cin >> str;
			break;
		case 1:

			cout << "begin: ";
			b = getInt();
			cout << "end: ";
			e = getInt();
			cout << substring(str,b, e)<<endl;
			break;
		case 2:
			cout << "begin: ";
			cin >> bs;
			cout << "end: ";
			cin >> es;
			cout << substring(str,bs, es) << endl;
			break;
		case 3:

			cout << "word to count: ";
			cin >> o;
			cout << count(str,o) << endl;
			break;
		case 4:

			cout << "find index of word: ";
			cin >> o;
			cout << getFirst(str,o) << endl;
			break;
		case 5:

			cout << "string to replace: " << endl;
			cin >> from;
			cout << "with string: " << endl;
			cin >> to;
			cout << replace(str,from, to) << endl;
			break;
		case 6:


			cout << "enter number of delimeters: ";
			n = getInt();
			del = new char[n];
			for (int i = 0; i < n; i++) {
				cout << "enter delimeter: " << endl;
				cin >> del[i];
			}
			cout << split(str,del, n) << endl;
			break;
		case 7:

			cout << "begin: ";
			b = getInt();
			cout << "end: ";
			e = getInt();
			cout << remove(str,b, e) << endl;
			break;
		case 8:

			cout << "begin: ";
			cin >> bs;
			cout << "end: ";
			cin >> es;
			cout << remove(str, bs, es) << endl;
			break;
		case 9:

			cout << "compare with string: " << endl;
			cin >> s;
			cout << str << '<' << s << ':' << boolalpha <<  (str < s) << endl;
			cout << str << "<=" << s << ':' << (str <= s) << endl;
			cout << str << '>' << s << ':' << (str > s) << endl;
			cout << str << ">=" << s << ':' << (str >= s) << endl;
			cout << str << "==" << s << ':' << (str == s) << endl;
			break;
		case 10:

			cout << "position: " << endl;
			i = getInt();
			cout << "str[i]: " << str.p[i] << endl;
			break;
		case 11:

			cout << "how many times: " << endl;
			i = getInt();
			cout << "str * num of times: " << str * i << endl;
			break;
		case 12:
			l = List();

			cout << "number of elements to add: ";
			n = getInt();

			for (int i = 0; i < n; i++) {
				cin >> o;
				l.add(o);
			}
			break;
		case 13:
			sort(l);
			cout << l;
			break;
		case 14:
			sort(l,reverseComparator);
			cout << l;
			break;
		case 15:

			cout << "position: ";
			i = getInt();
			cout << l[i] << endl;
			break;

		default:
			cout << "enter correct index" << endl;
			break;
		}
		}
		catch (const unsigned int indexError) {
			cout << "!!! incorrect indices !!!" << endl;
		}
		answ = printCommands();
	}
	
	return 0;
}