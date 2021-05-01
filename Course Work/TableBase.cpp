#include "TableBase.h"
#include <iomanip>

//private methods



void TableBase::printInFormat(std::string cell)
{
	std::cout << std::setw(15) << std::left << cell << '|';
}

void TableBase::printInFormat(double& cell)
{
	std::cout << std::setw(15) << std::left << std::setprecision(3) << std::fixed << cell << '|';
}

void TableBase::printLine()
{
	std::cout << std::endl;
	for (int i = 0; i < 6; ++i)
	{
		for (int i = 0; i < 16; ++i)
		{
			if (i != 15)
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