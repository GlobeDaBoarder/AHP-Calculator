#pragma once
#include <vector>
#include <string>
#include "IChosenParam.h"

class ChosenParam : public IChosenParam
{
private:
	std::vector<std::string> m_chosenParam;
	std::vector<Val> m_chosenValues;

	void LogInputError();

public:
	ChosenParam();
	~ChosenParam();

	void ChooseParams(std::vector<Phone>& phones) override;

	void printChosen() override;

	std::vector<std::string> getChosenParam() const override;
	std::vector<Val> getChosenValues() const override;
};

