#pragma once
#include <string>
#include <ostream>
#include <fstream>
#include "Param.h"

class IPhone
{
private:
	virtual std::ifstream& readParams(std::ifstream& input) = 0;
	virtual std::ostream& printPhone(std::ostream& output) const = 0;

public:

	virtual const std::string& getName() const = 0;

	virtual const Param& getDisplay() const = 0;
	virtual const Param& getMemSize() const = 0;
	virtual const Param& getRam() const = 0;
	virtual const Param& getPrice() const = 0;
	virtual const Param& getPerform() const = 0;
	virtual const Param& getBatt() const = 0;
	virtual const Param& getCam() const = 0;

	virtual void setName(std::string)  = 0;
	virtual void setDisplayVal(int) = 0;
	virtual void setMemSizeVal(int)  = 0;
	virtual void setRamVal(int) = 0;
	virtual void setPriceVal(int) = 0;
	virtual void setPerformVal(int) = 0;
	virtual void setBattVal(int) = 0;
	virtual void setCamVal(int) = 0;

	
};


