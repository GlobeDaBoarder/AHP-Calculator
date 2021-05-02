#pragma once
#include "ChosenParam.h"

class IValTable
{
public:
	virtual void printTable(ChosenParam& chosenParams, int& i) = 0;
	virtual std::vector<std::vector<double>> getContent() const = 0;
};