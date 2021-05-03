#pragma once
#include "ValTableBase.h"
class ValPair : public ValTableBase
{
private:
	std::vector<double> m_sum;

public:

	ValPair(ChosenParam& chosenParams, int& ind, bool& invert);
	~ValPair();

	void printTable(ChosenParam& chosenParams, int& i) override;
	std::vector<std::vector<double>> getContent() const override;

	std::vector<double> getSum() const;
};