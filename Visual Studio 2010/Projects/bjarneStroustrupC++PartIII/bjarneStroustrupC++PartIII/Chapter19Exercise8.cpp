/*
	TITLE			Allocator			     Chapter19Exercise8.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Implement an allocator (19.3.6) using malloc() and free() (B.10.4).
					Get vector as defined by the end of 19.4 to work for few simple cases.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 24.1.2016
*/
#include <iostream>
#include "Chapter19Exercise8.h"

int main ()
{
	try
	{
		// default
		Vector<int> v1;
		v1.push_back(2);
		std::cout <<"v1::size: " << v1.size();
		std::cout <<"\nv1::capacity: " << v1.capacity();
		std::cout <<"\nv1::operator[]: " << v1[0];

		//
		Vector<double> v2(10);
		std::cout <<"v2::size: " << v2.size();
		std::cout <<"\nv2::capacity: " << v2.capacity();
		std::cout <<"\nv2::operator[]: " << v2[9];

		//
		Vector<char> v3(20, 'a');
		std::cout <<"\nv3::size: " << v3.size();
		std::cout <<"\nv3::capacity: " << v3.capacity() <<'\n';
		v3[9] = 'b';

		for (int i = 8; i < v3.size(); ++i)
		{
			std::cout << v3[i] <<' ';
		}

		std::cout <<"\nat[0]: "<< v3.at(0);
		 
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}