#pragma once
#include <iostream>
#include <compare>
#include <stdexcept>


class Vector {
public:
	explicit Vector(size_t size = 0, int value = 0);
	Vector(const Vector& );
	Vector(Vector&& ) noexcept;
	~Vector();

	Vector& operator=(const Vector& other);
	int& operator[](const size_t );
	const int& operator[](const size_t ) const;
	const bool& operator==(const Vector& ) const noexcept;
	
	int* data() const;
	bool empty() const;
	int size() const;
	int capacity() const;
	void clear();
	void resize(size_t , int );
	void reserve(size_t );
	void push_back(int&& );
	void pop_back();
	void insert(size_t , int );
	void erase(int );

private:
	int m_size;
	int m_capacity;
	int* m_vector;

	void swap(Vector&) noexcept;
};

const bool& operator!=(const Vector&, const Vector&);
const bool& operator<(const Vector&, const Vector&);
const bool& operator<=(const Vector&, const Vector&);
const bool& operator>(const Vector&, const Vector&);
const bool& operator>=(const Vector&, const Vector&);
