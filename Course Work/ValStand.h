#pragma once
#include "ValTableBase.h"
#include "ValPairwise.h"
class ValStand : ValTableBase
{
private:
	std::vector<double> m_priority;

private:
	double avg(std::vector<double>& line);

public:
	ValStand(ValPair& pairw);
	~ValStand();

	void printTable(ChosenParam& chosenParams, int& i) override;
	std::vector<std::vector<double>> getContent() const override;
};