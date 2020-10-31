#include <iostream>

using namespace std;

int main() {

	// Pointerinits
	/*int i = 'a';
	const int ic = i;
	const int* pic = &ic;
	//int* const cpi = &ic;
	const int* const cpic = &ic;
	cout << i << endl;*/


	//Reference inits
	/*int i = 'a';
	const int ic = i;
	const int& ric = &ic;*/

	int aa = 1;
	int bb = 2;
	int cc = 3;
	int dd = 4;

	int* a = &aa;
	int* b = &bb;

	cout << "a=" << *a << "[" << a << "]" << ", b=" << *b << "[" << b << "]" << endl;

	swap(a, b);

	cout << "a=" << *a << "[" << a << "]" << ", b=" << *b << "[" << b << "]" << endl;


	int& c = cc;
	int& d = dd;

	cout << "c=" << &c << "[" << c << "]" << ", d=" << &d << "[" << d << "]" << endl;

	swap(c, d);

	cout << "c=" << &c << "[" << c << "]" << ", d=" << &d << "[" << d << "]" << endl;


	return 0;
}


void swap(int *a, int *b) {
	int c = *a;
	*a = *b;
	*b = c;
}

void swap(int& a, int& b) {

	int c = a;
	a = b;
	b = c;

}