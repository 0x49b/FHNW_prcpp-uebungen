#include <cctype>
#include <iostream>
#include <cmath>

using namespace std;


int main() {

	char s[] = "Hello World";
	int uppercase = 0;

	int len = sizeof(s);

	// for (int i = 0; i < len; i++) {
	//   if (isupper(s[i])) ++uppercase;
	// }
		

	for (auto i : s) if (isupper(i)) { ++uppercase;}

	cout << uppercase << " uppercase letters in: " << s << endl;



	return 0;
}

void sinus(int a, double b) {

	double bb = b / 6.28;

	for (int y = a; y >= -a; y--) {
		for (int x = 0; x < b; x++) {
			cout << ((int)round(a * sin(x / bb)) == y ? '*' : ' ');
		}
		cout << endl;
	}
}