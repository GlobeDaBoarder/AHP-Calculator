#pragma once
#include <vector>
#include "Stand.h"
#include "ValStand.h"
#include "FinalBase.h"

class Calculations :  public FinalBase
{
public:
	Calculations(Stand& stand, std::vector<ValStand>& valStandArr);
	~Calculations();

	void printTable(ChosenParam& chosenp, Stand& stand, std::vector<ValStand>& valStandArr);

	const std::vector<std::vector<double>>& getWXP() const;
};

