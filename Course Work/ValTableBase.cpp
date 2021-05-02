#include "ValTableBase.h"
#include <iomanip>
#include <sstream>

//private

void ValTableBase::ssprint(std::stringstream& ss, bool doubleWidth)
{
	std::cout << std::setw((doubleWidth)?30:15) << std::left << ss.str() << '|';
}

void ValTableBase::printInFormat(std::string cell, bool doubleWidth)
{
	std::stringstream ss;
	ss << ' ' << cell;
	ssprint(ss, doubleWidth);
}

void ValTableBase::printInFormat(double& cell, int precision)
{
	std::stringstream ss;
	ss << ' ' << std::setprecision(precision) << std::fixed << cell;
	ssprint(ss);
}

void ValTableBase::printInFormat(std::string name, double spec, bool doubleWidth)
{
	std::stringstream ss;
	ss << ' ' << name << "     " << std::setprecision(3) << std::fixed << spec;
	ssprint(ss, doubleWidth);
}

void ValTableBase::printLine()
{
	std::cout << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		int lim = 16;
		if (i == 0)
		{
			lim = 31;
		}

		for (int j = 0; j < lim; ++j)
		{
			if (j != lim -1)
			{
				std::cout << '_';
				continue;
			}
			std::cout << '|';
		}
	}
	std::cout << std::endl;
}

//public

ValTableBase::ValTableBase()
{
	std::vector<double> temp(3, 0);
	for (int i = 0; i < 3; ++i)
	{
		m_content.push_back(temp);
	}
}

void ValTableBase::printTable(ChosenParam& chosenParams, int& num)
{
	printInFormat(chosenParams.getChosenParam()[num], true) ;

	for (int i = 0; i < 3; ++i)
	{
		printInFormat(chosenParams.getChosenValues()[i].phoneName);
	}
	std::cout << std::endl;

	printInFormat(" ", true);
	for (int i = 0; i < 3; ++i)
	{
		printInFormat(chosenParams.getChosenValues()[i].stats[num].value);
	}

	printLine();

	for (int i = 0; i < 3; ++i)
	{
		printInFormat(chosenParams.getChosenValues()[i].phoneName, chosenParams.getChosenValues()[i].stats[num].value, true);
		for (int j = 0; j < 3; ++j)
		{
			printInFormat(m_content[i][j]);
		}
		printLine();
	}
}