#pragma once
#include "FinalBase.h"
#include "Calculations.h"

class Results : public FinalBase
{
private:
	std::vector<double> m_goal;
	std::vector<double> m_totals;

public:
	Results(Calculations& calc);
	~Results();

	void printTable(ChosenParam& chosenp);
	std::vector<double> getGoals() const;
};

