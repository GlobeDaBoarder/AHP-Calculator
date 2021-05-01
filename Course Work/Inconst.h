#pragma once
#include "Stand.h"
class Inconst : public TableBase
{
private:
	std::vector<double> m_weightscopy;
	std::vector<double> m_lambda;
	std::vector <double> m_weightsum;

private:
	void printweights();

public:
	Inconst(PairwiseComp& PCTable, Stand& stand);
	~Inconst();

	void printTable(ChosenParam& chosenParams) override;
	std::vector<std::vector<double>> getContent() const override;


};

