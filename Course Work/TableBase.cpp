#include "TableBase.h"
#include <iomanip>
#include <sstream>

//private methods


void TableBase::ssprint(std::stringstream& ss)
{
	std::cout << std::setw(15) << std::left << ss.str() << '|';
}

void TableBase::printInFormat(std::string cell)
{
	std::stringstream ss;
	ss << ' ' << cell;
	ssprint(ss);
}

void TableBase::printInFormat(double& cell, char postfix, int precision)
{
	std::stringstream ss;
	ss << ' ' << std::setprecision(precision) << std::fixed << cell << postfix;
	ssprint(ss);
}

void TableBase::printLine()
{
	std::cout << std::endl;
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 16; ++j)
		{
			if (j != 15)
			{
				std::cout << '_';
				continue;
			}
			std::cout << '|';
		}
	}
	std::cout << std::endl;
}

//public methods

TableBase::TableBase()
{
	std::vector<double> temp(5, 0);
	for (int i = 0; i < 5; ++i)
	{
		m_content.push_back(temp);
	}
}

void TableBase::printTable(ChosenParam& chosenParams)
{
	printInFormat(" ");
	for (auto& el : chosenParams.getChosenParam())
	{
		printInFormat(el);
	}
	printLine();


	for (int i = 0; i < 5; i++)
	{
		printInFormat(chosenParams.getChosenParam()[i]);
		for (int j = 0; j < 5; j++)
		{
			printInFormat(m_content[i][j]);
		}
		printLine();
	}
}