#pragma once
#include <vector>
#include "ChosenParam.h"
#include "IValTable.h"
class ValTableBase : public IValTable
{
protected:
	std::vector<std::vector<double>> m_content;

protected:
	void ssprint(std::stringstream& ss, bool doubleWidth = false);
	void printInFormat(std::string cell, bool doubleWidth = false);
	void printInFormat(double& cell, int precision = 3);
	void printLine();

public:
	ValTableBase();

	virtual void printTable(ChosenParam& chosenParams, int& i) = 0;
};