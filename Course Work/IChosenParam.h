#pragma once
#include "Phone.h"
#include "ValStruct.h"

class IChosenParam
{
public:
	virtual void ChooseParams(std::vector<Phone>& phones) = 0;
	virtual void printChosen() = 0;

	virtual std::vector<std::string> getChosenParam() const= 0;
	virtual std::vector<Val> getChosenValues() const = 0;
};