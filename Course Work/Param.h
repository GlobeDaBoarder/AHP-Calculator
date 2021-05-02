#pragma once
#include <string>
#include <iostream>
struct Param
{
	const std::string param;
	double value;

	Param();
	Param(std::string s, double spec = 0);
	friend void operator << (std::ostream& output, const Param&  param);
};