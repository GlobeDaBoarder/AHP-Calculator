#pragma once
#include "Stand.h"
class Inconst : public TableBase
{
private:
	std::vector<double> m_weightscopy;
	std::vector<double> m_lambda;
	std::vector <double> m_weightsum;
	double m_lambdaAvg;
	double m_consisIndex;
	double m_consisratio;
	static const double k_randomIndex;

private:
	double lambdaAvg();

	void printweights();
	void printWeightSum();
	void printLambda();
	void printConsisCalc();

public:
	Inconst(PairwiseComp& PCTable, Stand& stand);
	~Inconst();

	void printTable(ChosenParam& chosenParams) override;
	std::vector<std::vector<double>> getContent() const override;

	const double& getInconsis() const; 
};

