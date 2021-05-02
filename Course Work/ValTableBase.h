#pragma once
#include <vector>
#include "ChosenParam.h"
#include "IValTable.h"
class ValTableBase : public IValTable
{
protected:
	std::vector<std::vector<double>> m_content;

public:
	ValTableBase();

	//void printTable(ChosenParam& chosenParams) override;

};