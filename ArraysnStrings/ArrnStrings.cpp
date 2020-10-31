#include <iostream>

using namespace std;

/*void aufgabe1() {
	char msg[10]; 
	char* p;
	char msg2[] = "Hello";

	msg = "Bonjour";
	p = "Bonjour";

	msg = p;
	p = msg;

	p[0] = 'H', p[1] = 'i', p[2] = '\0';
	// *p and msg are now "Hi"  
	cout << "Content of array p[] is: " << p << endl;
}*/


void fillArr(int arr[], size_t len) {
	for (size_t i = 0; i < len; i++) {
		arr[i] *= arr[i];
	}
}

bool compare(const char* s1, const char* s2) {

	int i = 0;

	while (s1[i] != '\0') {
		i++;
	}

	int j = 0;

	while (s2[j]) j++;
	return i == j;
	
}


int main() {
	int y[] = { 0,1,2,3,4,5,6,7,8,9 };

	size_t size = 10;

	fillArr(y, size);

	for (size_t i = 0; i < size; i++) {
		std::cout << y[i] << std::endl;
	}

	const char string0[] = { 'J', 'a', 'a', 'v', 's', 's', '\0' };
	const char string1[] = { 'J', 'a', 'a', 'v', 's', '\0' };
	const char string2[] = "Jaavs";
	const char string3[] = { 'J', 'a', 'a' };

	const char* const strings[] = { string0, string1, string2, string3 };
	const size_t len = sizeof(strings) / sizeof(*strings);

	for (int i = 0; i < len; i++) {
		for (int j = i; j < len; j++) {
			cout << "string" << i << " and string" << j << " are of the same length: "
				<< boolalpha << compare(strings[i], strings[j]) << endl;
		}
	}
	

	return 0;
}


