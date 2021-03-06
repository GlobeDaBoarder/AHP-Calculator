#include "Stand.h"

//private method

void Stand::printweights() 
{
	printInFormat("WEIGHTS");
	for (auto& i : m_weight)
	{
		printInFormat(i, '%');
	}
	printLine();
}

double  Stand::avg(std::vector<double>& line)
{
	double tempSum = 0;
	for (auto& el : line)
	{
		tempSum += el;
	}
	return tempSum / line.size();
}

//public method
Stand::Stand(PairwiseComp& PCTable) : TableBase()
{
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			m_content[i][j] = PCTable.getContent()[i][j] / PCTable.getSum()[j];
		}

		m_weight.push_back(avg(m_content[i])*100);
	}
}

Stand::~Stand()
{
}

void Stand::printTable(ChosenParam& chosenparams)
{
	std::cout << "\n\nStandardized matrix (every element of the Pairwise comparison divided by it's sum):\n";

	TableBase::printTable(chosenparams);

	printweights();

	std::cout << "Weight represents average of sum of every ROW" << std::endl;
}

std::vector<std::vector<double>> Stand::getContent() const { return m_content; }
std::vector<double> Stand::getWeights() const { return m_weight; }

