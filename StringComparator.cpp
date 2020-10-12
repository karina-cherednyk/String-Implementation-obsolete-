#include "String.h"
const int compareDirect(const String& s1, const String& s2) {
	const char* ch1 = s1.p;
	const char* ch2 = s2.p;

	while (*ch1 && *ch2) {
		if (*ch1 == *ch2) ch1++, ch2++;
		else return *ch1 - *ch2;
	}
	if (*ch1) return 1;
	if (*ch2) return -1;
	return 0;
}
const int compareReverse(const String& s1, const String& s2) {
	const char* ch1 = s1.p;
	const char* ch2 = s2.p;

	while (*ch1 && *ch2) {
		if (*ch1 == *ch2) ch1++, ch2++;
		else return *ch2 - *ch1;
	}
	if (*ch1) return -1;
	if (*ch2) return 1;
	return 0;
}