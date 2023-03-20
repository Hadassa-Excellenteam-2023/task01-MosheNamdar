#include "Vector.h"

//c-tor
Vector::Vector(size_t size, int value)
	: m_size(size), m_capacity(size), m_vector(new int[size])
{
	for (size_t i = 0; i < size; i++)
		m_vector[i] = value;
}

//copy c-tor
Vector::Vector(const Vector& other)
	: m_size(other.m_size), m_capacity(other.m_capacity), m_vector(new int[m_capacity])
{
	for (size_t i = 0; i < m_size && i < m_capacity; i++) {
		m_vector[i] = other.m_vector[i];
	}
}

//move c-tor
Vector::Vector(Vector&& other) noexcept 
	: m_size(other.m_size), m_capacity(other.m_capacity), m_vector(other.m_vector)
{
	other.m_size = 0;
	other.m_capacity = 0;
	other.m_vector = nullptr;
}

//d-tor
Vector::~Vector()
{
	delete[] m_vector;
}

//Assigns the specified other vector to this vector, copying its contents.
//Parameters: other: The vector to assign.
Vector& Vector::operator=(const Vector& other)
{
	if (this != &other)
	{
		Vector tmp(other);
		this->swap(tmp);
	}
	return *this;
}

//Returns a reference to the element at the specified index in the vector.
//Parameters: i: The index of the element to retrieve.
int& Vector::operator[](const size_t i)
{
	try {
		if (i >= m_size)
			throw std::out_of_range("Index out of range");
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}

	return m_vector[i];

}

//Returns a const reference to the element at the specified index in the vector.
//Parameters: i: The index of the element to retrieve.
const int& Vector::operator[](const size_t i) const
{
	try {
		if (i >= m_size)
			throw std::out_of_range("Index out of range");
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}

	return m_vector[i];
}

//Compares this vector to the specified other vector for equality.
//Parameters: other: The vector to compare to.
//Returns: true: If the vectors are equal. false : Otherwise.
const bool& Vector::operator==(const Vector& other) const noexcept
{
	if ((*this).size() != other.m_size)
		return false;

	for (size_t i = 0; i < (*this).size(); i++)
		if ((*this)[i] != other.m_vector[i])
			return false;

	return true;
}

//Swaps the contents of this vector with the specified other vector.
//Parameters: other: The vector to swap with.
void Vector::swap(Vector& other) noexcept
{
	std::swap(m_size, other.m_size);
	std::swap(m_capacity, other.m_capacity);
	std::swap(m_vector, other.m_vector);
}


int* Vector::data() const
{
	return m_vector;
}

bool Vector::empty() const
{
	return m_size == 0;
}

int Vector::size() const
{
	return m_size;
}

int Vector::capacity() const
{
	return m_capacity;
}

void Vector::clear()
{
	m_size = 0;
	m_capacity = 0;
	m_vector = nullptr;
}

//Resizes the vector to the specified size and sets all new elements to the specified value.
//Parameters: size: The new size of the vector. value : The value to set new elements to.
void Vector::resize(size_t size, int value)
{
	if (size > m_size) {
		if (size > m_capacity) {
			reserve(size);
		}
		for (size_t i = m_size; i < size; i++) {
			m_vector[i] = value;
		}
	}
	m_size = size;
}

//Reserves memory for the vector to accommodate at least the specified capacity.
//Parameters: capacity: The minimum capacity to reserve.
void Vector::reserve(size_t capacity)
{
	if (capacity > m_capacity) {
		int* vector = new int[capacity];
		for (size_t i = 0; i < m_size; i++) {
			vector[i] = m_vector[i];
		}
		delete[] m_vector;
		m_vector = vector;
		m_capacity = capacity;
	}
}

//Adds a new element to the end of the vector with the specified value.
//Parameters: value: The value of the new element.
void Vector::push_back(int&& value)
{
	if (m_size == 0)
		reserve(1);

	if (m_size == m_capacity)
	{
		if (m_size < 128)
			reserve(m_capacity * 2);
		else
			reserve(m_capacity * 1.5);
	}

	m_vector[m_size++] = value;
}

//Removes the last element from the vector.
void Vector::pop_back()
{
	if (m_size == 0)
		return;

	m_size--;
}

/**
 * Inserts an element at the specified index in the vector.
 *
 * @param index The index at which to insert the element.
 * @param value The value of the element to insert.
 * @throws std::out_of_range if the index is out of range.
 */
void Vector::insert(size_t index, int value)
{
	try {
		if (index > m_size)
			throw std::out_of_range("Index out of range");

		if (m_size == m_capacity)
			reserve(m_capacity * 2);

		for (size_t i = m_size - 1; i >= static_cast<int>(index); i--)
			m_vector[i + 1] = m_vector[i];

		m_vector[index] = value;
		m_size++;
	}
	catch (const std::out_of_range& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

/**
 * Removes the element at the specified index from the vector.
 *
 * @param index The index of the element to remove.
 * @throws std::out_of_range if the index is out of range.
 */
void Vector::erase(int index)
{
	try {
		if (index >= m_size)
			throw std::out_of_range("Index out of range");

		for (size_t i = index; i < m_size - 1; i++)
			m_vector[i] = m_vector[i + 1];

		m_size--;
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
}

/**
 * Compares two vectors for inequality.
 *
 * @param v1 The first vector to compare.
 * @param v2 The second vector to compare.
 * @return true if the vectors are not equal, false otherwise.
 */
const bool& operator!=(const Vector& v1, const Vector& v2) 
{
	return !(v1 == v2);
}

/**
 * Compares two vectors for less than.
 *
 * @param v1 The first vector to compare.
 * @param v2 The second vector to compare.
 * @return true if v1 is less than v2, false otherwise.
 */
const bool& operator<(const Vector& v1, const Vector& v2) 
{
	size_t size;

	if (v1.size() > v2.size())
		size = v2.size();
	else
		size = v1.size();

	for (size_t i = 0; i < size; i++)
	{
		if (v1[i] < v2[i])
			return true;

		if (v1[i] > v2[i])
			return false;
	}

	return v1.size() < v2.size();
}

/**
 * Compares two vectors for less than or equal to.
 *
 * @param v1 The first vector to compare.
 * @param v2 The second vector to compare.
 * @return true if v1 is less than or equal to v2, false otherwise.
 */
const bool& operator<=(const Vector& v1, const Vector& v2) 
{
	return v1 == v2 || v1 < v2;
}

/**
 * Compares two vectors for greater than.
 *
 * @param v1 The first vector to compare.
 * @param v2 The second vector to compare.
 * @return true if v1 is greater than v2, false otherwise.
 */
const bool& operator>(const Vector& v1, const Vector& v2) 
{
	return !(v1 <= v2);
}

/**
 * Compares two vectors for greater than or equal to.
 *
 * @param v1 The first vector to compare.
 * @param v2 The second vector to compare.
 * @return true if v1 is greater than or equal to v2, false otherwise.
 */
const bool& operator>=(const Vector& v1, const Vector& v2) 
{
	return !(v1 < v2);
}
