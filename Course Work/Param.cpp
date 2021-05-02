#include "Param.h"

Param::Param()
	: param(""), value(0)
{
}

Param::Param(std::string s, double spec)
	:param(s), value(spec)
{
}

void operator << (std::ostream& output, const Param& param)
{
	std::cout << param.param << ": " << param.value << std::endl;
}