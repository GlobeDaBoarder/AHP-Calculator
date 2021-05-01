#pragma once
#include "ChosenParam.h"
class ITable
{
public:
	virtual void printTable(ChosenParam& chosenParams) = 0;
	virtual std::vector<std::vector<double>> getContent() const = 0;
};