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
			m_weightXprior[i][j] = (stand.getWeights()[i]/100) * valStandArr[i].getPriority()[j];
		}
	}
}

Calculations::~Calculations()
{
}

void Calculations::printTable(ChosenParam& chosenp, Stand& stand, std::vector<ValStand>& valStandArr)
{
	printInFormat("Criteria", true);
	printInFormat("Models", true);
	printInFormat("Priority", true);
	printInFormat("", true);
	printInFormat("Weight", true);
	printInFormat("", true);
	printInFormat("weight * priority", true);

	printLine(true);

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (j == 0)
			{
				printInFormat(chosenp.getChosenParam()[i], false);
			}
			else
			{
				printInFormat(' ');
			}

			printInFormat(chosenp.getChosenValues()[j].phoneName, false);
			printInFormat(valStandArr[i].getPriority()[j], false);
			printInFormat('*');
			printInFormat((stand.getWeights()[i]/100), false);
			printInFormat('=');
			printInFormat(m_weightXprior[i][j]);

			if (j != 2)
			{
				std::cout << std::endl;
			}
		}

		printLine(false);
	}
}