#include <iostream>
using namespace std;

#define MAX(a,b) ((a)<(b)?(b):(a))
#define TypeSize(type) left << #type << sizeof(type) << (sizeof(type) == 1 ? " Byte" : " Bytes")

int main()
{
	int x = 5, y = 10;
	int z MAX(x++, y++);
	
	cout << "x=" << x << ", y=" << y << ", z=" << z <<endl;

	return 0;
}

void typesizes() {
	cout << TypeSize(bool) << endl;
	cout << TypeSize(char) << endl;
	cout << TypeSize(byte) << endl;
	cout << TypeSize(short) << endl;
	cout << TypeSize(int) << endl;
	cout << TypeSize(long) << endl;
	cout << TypeSize(long long) << endl;
	cout << TypeSize(float) << endl;
	cout << TypeSize(double) << endl;
	cout << TypeSize(long double) << endl;
}