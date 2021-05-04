#include "Calculations.h"

Calculations::Calculations(Stand& stand, std::vector<ValStand>& valStandArr)
{
	std::vector<double> temp(3, 0);
	for (int i = 0; i < 5; ++i)
	{
		m_weightXprior.push_back(temp);
	}

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			m_weightXprior[i][j] = stand.getWeights()[i] * valStandArr[i].getPriority()[j];
		}
	}
}

Calculations::~Calculations()
{
}

void Calculations::printTable()
{
	printInFormat("Criteria", true);
	printInFormat("Models", true);
	printInFormat("Priority", true);
	printInFormat("", true);
	printInFormat("Weight", true);
	printInFormat("", true);
	printInFormat("weight * priority", true);

	printLine(true);

	for (int i = 0; i < 7; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			for (int q = 0; q < 3; ++q)
			{

			}
		}
	}
}