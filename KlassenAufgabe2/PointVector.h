#pragma once
#include <initializer_list>
#include <memory>
#include "Point.h"


class PointVector {
	std::unique_ptr<Point[]> m_points;
	size_t m_size, m_capacity;

	void resize(size_t capacity);

public:
	PointVector();
	PointVector(const std::initializer_list<Point>& pts);
	PointVector(const PointVector& pv);
	
	PointVector(PointVector&& v);
	PointVector& operator=(PointVector&& v);

	void clear();
	size_t getSize() const { return m_size; }
	void print() const;
	void pushBack(const Point& p);
	void insert(const size_t pos, const Point& p);
	void remove(const size_t pos);
	bool get(const size_t pos, Point& p) const;
	Point& at(const size_t pos);
	const Point& at(const size_t pos) const;
};