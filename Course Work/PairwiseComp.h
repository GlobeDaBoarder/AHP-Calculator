#pragma once
#include <vector>
#include "TableBase.h"

class PairwiseComp  : public TableBase
{
private:
	std::vector<double> m_sum;

private:
	void CountSum();
	double ReadEvaluation() const;
	
public:
	PairwiseComp();
	~PairwiseComp();

	void printTable(ChosenParam& chosenParams) override;
	std::vector<std::vector<double>> getContent() const override;

	void AssessContent(ChosenParam& chosenParams);
	std::vector<double> getSum() const;
};

