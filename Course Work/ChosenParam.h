#pragma once
#include <vector>
#include <string>
#include "Param.h"
#include "IChosenParam.h"

class ChosenParam : public IChosenParam
{
private:
	std::vector<std::string> m_chosenParam;
	std::vector<Param> m_IphoneChosen;
	std::vector<Param> m_SamsungChosen;
	std::vector<Param> m_HuaweiChosen;

	void LogInputError();

public:
	ChosenParam();
	~ChosenParam();

	void ChooseParams(Phone&, Phone&, Phone&) override;

	void printChosen() override;

	std::vector<std::string> getChosenParam() const override;
	std::vector<Param> getIphoneParam() const override;
	std::vector<Param> getSamsungParam()const override;
	std::vector<Param> getHuaweiParam() const override;
};

