#include "Results.h"
#include "Calculations.h"

Results::Results(Calculations& calc)
{
	m_weightXprior = calc.getWXP();

	for (int i = 0; i < 3; ++i)
	{
		double tempHorSum = 0;
		for (int j = 0; j < 5; ++j)
		{
			tempHorSum += m_weightXprior[j][i];
		}

		m_goal.push_back(tempHorSum);
	}

	for (int i = 0; i < 5; ++i)
	{
		double tempVertSum = 0;
		for (int j = 0; j < 3; ++j)
		{
			tempVertSum += m_weightXprior[i][j];
		}

		m_totals.push_back(tempVertSum);
	}
}

Results::~Results()
{
}

void Results::printTable(ChosenParam& chosenp)
{
	std::cout << std::endl << std::endl;

	printInFormat("model/criteria", true);
	for (int i = 0; i < 5; ++i)
	{
		printInFormat(chosenp.getChosenParam()[i], true);
	}
	printInFormat("GOAL", true);
	printLine(true);

	for (int i = 0; i < 3; ++i)
	{
		printInFormat(chosenp.getChosenValues()[i].phoneName, true);
		for (int j = 0; j < 5; ++j)
		{
			printInFormat(m_weightXprior[j][i], true);
		}
		printInFormat(m_goal[i], true);
		printLine(true);
	}

	printInFormat("total sums", true);
	for (int i = 0; i < 5; ++i)
	{
		printInFormat(m_totals[i], true);
	}
	printInFormat(" ", true);
	printLine(true);
}

std::vector<double> Results::getGoals() const { return m_goal; }