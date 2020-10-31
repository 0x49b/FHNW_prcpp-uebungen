#include "pointvector.h" 
#include <iostream> 
using namespace std;

int main() {
	Point p1(1, 2), p2(2, 3), p3(3, 4), p4(4, 5);
	initializer_list<Point> points = { p1, p2, p3, p4 };

	PointVector pa1;
	PointVector pa2(points);
	PointVector pa3(pa2);

	cout << "print test" << endl;
	pa1.print(); pa2.print(); pa3.print();

	cout << "clear and size test" << endl;
	pa2.clear();
	cout << boolalpha << (pa1.getSize() == 0) << endl;
	cout << boolalpha << (pa2.getSize() == 0) << endl;
	cout << boolalpha << (pa3.getSize() == 4) << endl;
	pa2.print();

	cout << "push-back test" << endl;
	pa3.pushBack(Point(5, 6));
	cout << boolalpha << (pa3.getSize() == 5) << endl;
	pa3.print();

	cout << "remove test" << endl;
	pa3.remove(5); pa3.remove(4); pa3.remove(0); pa3.remove(1);
	cout << boolalpha << (pa3.getSize() == 2) << endl;
	pa3.print();

	cout << "insert test" << endl;
	pa3.insert(0, p1); pa3.insert(2, p3); pa3.insert(4, Point(5, 6));
	cout << boolalpha << (pa3.getSize() == 5) << endl;
	pa3.print();

	cout << "at test" << endl;
	try {
		pa3.at(2).print(); cout << endl;
		pa3.at(10).print(); cout << endl;
	}
	catch (const out_of_range& ex) {
		cout << ex.what() << endl;
	}

	cout << "move semantics test" << endl;
	PointVector pa4(move(pa3));
	cout << boolalpha << (pa3.getSize() == 0) << endl;
	cout << boolalpha << (pa4.getSize() == 5) << endl;
	pa4.print();
	pa1 = move(pa4);
	cout << boolalpha << (pa4.getSize() == 0) << endl;
	cout << boolalpha << (pa1.getSize() == 5) << endl;
	pa1.print();
}