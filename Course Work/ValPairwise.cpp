#include "ValPairwise.h"

ValPair::ValPair(ChosenParam& chosenParams, int& ind, bool& invert): ValTableBase()
{
	if (invert)
	{
		for (int i = 0; i < 3; ++i)
		{
			double tempSum = 0;
			for (int j = 0; j < 3; ++j)
			{
				m_content[j][i] = chosenParams.getChosenValues()[i].stats[ind].value /
					chosenParams.getChosenValues()[j].stats[ind].value;
				tempSum += m_content[j][i];
			}
			m_sum.push_back(tempSum);
		}

		std::cout << "EVALUATION OF THIS TABLE ARE INVERTED! BECAUSE THE LESS THE PRICE PARAMETER IS, "
			"THE BETTER, UNLIKE WITH ANY OTHER PARAMETERS" << std::endl;
		return;
	}

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

	std::cout << "SUM is sum of every element in each column\n\n";
}

std::vector<std::vector<double>> ValPair::getContent() const { return m_content; }

std::vector<double> ValPair::getSum() const { return  m_sum; }