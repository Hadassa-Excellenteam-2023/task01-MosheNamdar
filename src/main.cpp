#pragma once
#include <iostream>
#include "Vector.h"


int main()
{
	
	Vector vec1;
	std::cout << "vec1 size: " << vec1.size() << ", vec1 capacity: " << vec1.capacity() << std::endl;

	Vector vec2(4, 20);
	std::cout << "vec2 size: " << vec2.size() << ", vec2 capacity: " << vec2.capacity() << std::endl;
	for (size_t i = 0; i < vec2.size(); i++)
		std::cout << vec2[i] << std::endl;

	Vector vec3 = vec2;
	std::cout << "vec3 size: " << vec3.size() << ", vec3 capacity: " << vec3.capacity() << std::endl;
	for (size_t i = 0; i < vec3.size(); i++)
		std::cout << vec3[i] << std::endl;

	Vector vec4 = std::move(vec2);
	std::cout << "vec4 size: " << vec4.size() << ", vec4 capacity: " << vec4.capacity() << std::endl;
	for (size_t i = 0; i < vec4.size(); i++)
		std::cout << vec4[i] << std::endl;

	vec4.insert(2, 3);
	std::cout << "vec4 size: " << vec4.size() << ", vec4 capacity: " << vec4.capacity() << std::endl;
	for (size_t i = 0; i < vec4.size(); i++)
		std::cout << vec4[i] << std::endl;

	vec4.erase(2);
	std::cout << "vec4 size: " << vec4.size() << ", vec4 capacity: " << vec4.capacity() << std::endl;
	for (size_t i = 0; i < vec4.size(); i++)
		std::cout << vec4[i] << std::endl;

	if (vec1.empty())
		std::cout << "vec1 is empty\n";

	vec2.clear();
	std::cout << "vec2 size: " << vec2.size() << ", vec2 capacity: " << vec2.capacity() << std::endl;
	for (size_t i = 0; i < vec2.size(); i++)
		std::cout << vec2[i] << std::endl;

	vec3.reserve(6);
	std::cout << "vec3 size: " << vec3.size() << ", vec3 capacity: " << vec3.capacity() << std::endl;

	vec4.push_back(7);
	std::cout << "vec4 size: " << vec4.size() << ", vec4 capacity: " << vec4.capacity() << std::endl;
	for (size_t i = 0; i < vec4.size(); i++)
		std::cout << vec4[i] << std::endl;

	vec4.pop_back();
	std::cout << "vec4 size: " << vec4.size() << ", vec4 capacity: " << vec4.capacity() << std::endl;
	for (size_t i = 0; i < vec4.size(); i++)
		std::cout << vec4[i] << std::endl;
	
	if (vec2 != vec3)
		std::cout << "vec2 != vec3" << std::endl;

	if(vec1 == vec2)
		std::cout << "vec1 == vec2" << std::endl;

	if(vec3 > vec1)
		std::cout << "vec3 > vec1" << std::endl;

	if(vec1 < vec3)
		std::cout << "vec1 < vec3" << std::endl;

	if(vec2 <= vec1)
		std::cout << "vec2 <= vec3" << std::endl;

	if(vec2 >= vec1)
		std::cout << "vec2 >= vec1" << std::endl;



	return 0;
}
