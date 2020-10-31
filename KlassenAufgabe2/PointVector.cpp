#include <iostream>
#include "PointVector.h"
#include <exception>

using namespace std;



void PointVector::resize(size_t capacity){

	m_capacity = capacity;
	
	if (capacity < m_size) m_size = capacity;

	auto pts = new Point[m_capacity];

	auto v = make_unique<Point[]>(m_capacity);

	for (size_t i = 0; i < m_size; i++) v[i] = m_points[i];
	m_points = move(v);
	
}




PointVector::PointVector() : m_size(0), m_capacity(0), m_points(nullptr){}

PointVector::PointVector(const std::initializer_list<Point>& pts):
	m_points(make_unique<Point[]>(pts.size()))
	, m_size(pts.size())
	, m_capacity(pts.size())
{
	int i = 0;
	
	for (const auto& p : pts) {
		m_points[i++] = p;
	}

}

PointVector::PointVector(const PointVector& pv) : 
	m_points(make_unique<Point[]>(pv.m_size)), 
	m_size(pv.m_size), 
	m_capacity(pv.m_size)
{
	for (size_t i = 0; i < m_size; i++) {
		m_points[i] = pv.m_points[i];
	}
}

//Verschiebekonstruktor
PointVector::PointVector(PointVector&& v) :
	m_points(std::move(v.m_points)), 
	m_size(v.m_size), 
	m_capacity(v.m_capacity) 
{
	v.m_size = 0;
	v.m_capacity = 0;
}

//Verschiebeoperator
PointVector& PointVector::operator=(PointVector&& v)
{
	if (this != &v) {
		m_size = v.m_size; v.m_size = 0;
		m_capacity = v.m_capacity; v.m_capacity = 0;

		m_points = move(v.m_points);
	}
	return *this;
}

void PointVector::clear(){
	resize(0);
}

void PointVector::print() const{
	cout << "[";
	if (m_size) {
		for (size_t i = 0; i < m_size - 1; i++) {
			at(i).print();
			cout << ",";
		}
		at(m_size - 1).print();
	}
	cout << "]" << endl;
}

void PointVector::pushBack(const Point& p){

	if (m_size == m_capacity) resize(3 * m_size / 2 + 1);
	m_points[m_size++] = p;

}

void PointVector::insert(const size_t pos, const Point& p){
	if (m_size == m_capacity) resize(3 * m_size / 2 + 1);
	
	for (size_t i = m_size; i > pos; i--) {
		m_points[i] = m_points[i - 1];
	}
	m_points[pos] = p;
	m_size++;
}

void PointVector::remove(const size_t pos){
	if (pos < m_size) {
		for (size_t i = pos; i < m_size; i++) {
			m_points[i] = m_points[i + 1];
		}
		m_size--;
	}
}

bool PointVector::get(const size_t pos, Point& p) const{
	if (pos < m_size) {
		p = m_points[pos];
		return true;
	}
	return false;
}

Point& PointVector::at(const size_t pos){
	if (pos < m_size) {
		return m_points[pos];
	}
	throw out_of_range("pos is out of range");
}

const Point& PointVector::at(const size_t pos) const{
	if (pos < m_size) {

		return m_points[pos];
	}

	throw out_of_range("pos is out of range");
	
}
