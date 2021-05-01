#pragma once
#include <string>
#include <iostream>
struct Param
{
	const std::string param;
	int value;

	friend void operator << (std::ostream& output, const Param&  param);
};