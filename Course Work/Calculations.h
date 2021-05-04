#pragma once
#include <vector>
#include "Stand.h"
#include "ValStand.h"
#include "ChosenParam.h"
#include "FinalPrinter.h"

class Calculations : private FinalPrinter
{
private:
	std::vector<std::vector<double>> m_weightXprior;

public:
	Calculations(Stand& stand, std::vector<ValStand>& valStandArr);
	~Calculations();

	void printTable(ChosenParam& chosenp, Stand& stand, std::vector<ValStand>& valStandArr);
};

