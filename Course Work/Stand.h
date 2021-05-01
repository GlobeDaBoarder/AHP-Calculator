#pragma once
#include <vector>
#include "PairwiseComp.h"
class Stand : public TableBase
{
protected:
	std::vector<double> m_weight;

private:
	double  avg(std::vector<double>& line);
	void printweights();

public:
	Stand(PairwiseComp& PCTable);
	~Stand();

	void printTable(ChosenParam& chosenParams) override;

	std::vector<std::vector<double>> getContent() const override;
	std::vector<double> getWeights() const;
};

