#pragma once
#include <vector>
#include "ChosenParam.h"
#include "ITable.h"
class TableBase : public ITable
{
protected:
	std::vector<std::vector<double>> m_content;

	void printInFormat(std::string cell);
	void printInFormat(double& cell);
	void printLine();

public:
	TableBase();

	void printTable(ChosenParam& chosenParams) override;
};