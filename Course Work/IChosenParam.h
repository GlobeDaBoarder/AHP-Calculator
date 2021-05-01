#pragma once
#include "Phone.h"
class IChosenParam
{
public:
	virtual void ChooseParams(Phone&, Phone&, Phone&) = 0;
	virtual void printChosen() = 0;

	virtual std::vector<std::string> getChosenParam() const= 0;
	virtual std::vector<Param> getIphoneParam() const = 0;
	virtual std::vector<Param> getSamsungParam() const = 0;
	virtual std::vector<Param> getHuaweiParam() const = 0;
};