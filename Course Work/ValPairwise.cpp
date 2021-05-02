#include "ValPairwise.h"

ValPair::ValPair(ChosenParam& chosenParams, int& ind): ValTableBase()
{
	for (int i = 0; i < 3; ++i)
	{
		double tempSum = 0;
		for (int j = 0; j < 3; ++j)
		{
			m_content[j][i] = chosenParams.getChosenValues()[j].stats[ind].value /
				chosenParams.getChosenValues()[i].stats[ind].value;
			tempSum += m_content[j][i];
		}
		m_sum.push_back(tempSum);
	}
	
}

ValPair::~ValPair()
{
}

void ValPair::printTable(ChosenParam& chosenparams, int& ind)
{
	ValTableBase::printTable(chosenparams, ind);

	printInFormat("SUM", true);
	for (auto& i : m_sum)
	{
		printInFormat(i);
	}

	printLine();
}

std::vector<std::vector<double>> ValPair::getContent() const { return m_content; }