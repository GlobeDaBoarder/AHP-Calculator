#pragma once
#include <vector>
#include "FinalPrinter.h" 
#include "ChosenParam.h"

class FinalBase : protected FinalPrinter
{
protected:
	std::vector<std::vector<double>> m_weightXprior;
};