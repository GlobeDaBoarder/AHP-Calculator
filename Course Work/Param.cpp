#include "Param.h"


void operator << (std::ostream& output, const Param& param)
{
	std::cout << param.param << ": " << param.value << std::endl;
}