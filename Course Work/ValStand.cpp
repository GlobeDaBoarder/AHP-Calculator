#include "ValStand.h"

//private 


double  ValStand::avg(std::vector<double>& line)
{
	double tempSum = 0;
	for (auto& el : line)
	{
		tempSum += el;
	}
	return tempSum / line.size();
}


//public 


ValStand::ValStand(ValPair& pairw) : ValTableBase()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			m_content[i][j] = pairw.getContent()[i][j] / pairw.getSum()[j];
		}

		m_priority.push_back(avg(m_content[i]));
	}
}

ValStand::~ValStand()
{
}

void ValStand::printTable(ChosenParam& chosenParams, int& i)
{
	std::cout << "Standardized matrix(every element of the Pairwise comparison divided by it's sum):\n\n";

	ValTableBase::printTable(chosenParams, i);

	printInFormat("PRIORITY", true);
	for (auto& i : m_priority)
	{
		printInFormat(i);
	}
	printLine();

	std::cout << "PRIORITY  represents average of sum of every ROW\n\n";
}

std::vector<std::vector<double>> ValStand::getContent() const { return m_content; }

std::vector<double> ValStand::getPriority() const { return m_priority; }