#include "Inconsist.h"
#include <iomanip>

//private

const double Inconst::k_randomIndex = 1.12;

double Inconst::lambdaAvg()
{
	double tempAvg = 0;
	for (double& el : m_lambda)
	{
		tempAvg += el;
	}

	return tempAvg / m_lambda.size();
}

void Inconst::printweights()
{
	printInFormat("WEIGHTS");
	for (auto& i : m_weightscopy)
	{
		printInFormat(i, '%');
	}
	printLine();
}

void Inconst::printWeightSum()
{
	printInFormat("WEIGHTED SUM");
	for (auto& i : m_weightsum)
	{
		printInFormat(i, ' ' , 4);
	}
	printLine();
}

void Inconst::printLambda()
{
	printInFormat("LAMBDA");
	for (auto& i : m_lambda)
	{
		printInFormat(i, ' ', 6);
	}
	printLine();
}

void Inconst::printConsisCalc()
{
	std::cout << std::setw(20) << ' '  << "Lambda avg = " << m_lambdaAvg << std::endl;
	std::cout << std::setw(20) << ' ' << "Consistency index = (Lambda avg - n)/n-1= " << m_consisIndex << std::endl;
	std::cout << std::setw(20) << ' '  << "Consistency ratio " << m_consisratio * 100 << '%' << std::endl;
	std::cout << std::setw(20) << ' ' << "Consistency ratio should be <10% " << std::endl;
}

//public

Inconst::Inconst(PairwiseComp& PCTable, Stand& stand) : TableBase()
{
	m_weightscopy = stand.getWeights();
	for (int i = 0; i < 5; ++i)
	{
		double tempSum = 0;
		for (int j = 0; j < 5; ++j)
		{
			m_content[i][j] = PCTable.getContent()[i][j] * (m_weightscopy[j]/100);
			tempSum += m_content[i][j];
		}

		m_weightsum.push_back(tempSum);
		m_lambda.push_back(m_weightsum[i] /( m_weightscopy[i]/100));
	}

	m_lambdaAvg = lambdaAvg();
	m_consisIndex = (m_lambdaAvg - m_lambda.size()) / (m_lambda.size() - 1);
	m_consisratio = m_consisIndex / k_randomIndex;
}

Inconst::~Inconst()
{
}

void Inconst::printTable(ChosenParam& chosenparams)
{
	std::cout << "\n\nInonsistency matrix(every element of pairwise comparison multiplied by the weight o it's row\n";

	printweights();
	TableBase::printTable(chosenparams);

	printWeightSum();

	printLambda();

	std::cout << "WEIGHTED SUM is sum of each RO of this matrix \n";
	std::cout << "LAMBDA is WEIGHTED SUM devided by its WEIGHT \n\n";

	printConsisCalc();
}

std::vector<std::vector<double>> Inconst::getContent() const { return m_content; }
const double& Inconst::getInconsis() const { return m_consisratio; }