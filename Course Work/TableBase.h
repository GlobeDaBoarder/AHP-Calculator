#pragma once
#include <vector>
#include "ChosenParam.h"
#include "ITable.h"
class TableBase : public ITable
{
protected:
	std::vector<std::vector<double>> m_content;

protected:
	void ssprint(std::stringstream& ss);
	void printInFormat(std::string cell);
	void printInFormat(double& cell, char postfix = ' ', int precision = 3);
	void printLine();

public:
	TableBase();

	void printTable(ChosenParam& chosenParams) override;
};