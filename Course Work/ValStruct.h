#pragma once
#include "Param.h"
#include <string> 
#include <vector>

struct Val
{
	std::string phoneName;
	std::vector<Param> stats;

	Val();
};