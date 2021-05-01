#include "ChosenParam.h"
#include <iostream>
#include <vector>
#include <iomanip>

//private methods

void ChosenParam::LogInputError()
{
	std::cout << "[WRONG INPUT]" << std::endl;
}

// public methods:

ChosenParam::ChosenParam()
{
}

ChosenParam::~ChosenParam()
{
}

void ChosenParam::ChooseParams(Phone& Iphone, Phone& Samsung, Phone& Huawei)
{
	std::cout << "Type in numbers from 1 to 7 to choose parameters (choose 5 of them)" << std::endl;
	std::cout << "1 -- Display \t" << "2 -- Memory size \t"
		<< "3 -- RAM \t" << "4 -- Price \t"
		<< "5 --Performance \t" << "6 -- Battery \t"
		<< "7 -- Camera" << std::endl;

	int inVal = 0;
	std::vector<int> inUse;
	for (int i = 0; i < 5; ++i)
	{
		std::cin >> inVal;
		bool goToSwitch = true;

		for (auto& in : inUse)
		{
			if (inVal == in)
			{
				LogInputError();
				--i;
				goToSwitch = false;
				break;
			}
		}

		if (goToSwitch)
		{
			switch (inVal)
			{
			case 1:
				m_chosenParam.push_back("Display");
				m_IphoneChosen.push_back(Iphone.getDisplay());
				m_SamsungChosen.push_back(Samsung.getDisplay());
				m_HuaweiChosen.push_back(Huawei.getDisplay());
				inUse.push_back(inVal);
				break;
			case 2:
				m_chosenParam.push_back("Memory size");
				m_IphoneChosen.push_back(Iphone.getMemSize());
				m_SamsungChosen.push_back(Samsung.getMemSize());
				m_HuaweiChosen.push_back(Huawei.getMemSize());
				inUse.push_back(inVal);
				break;
			case 3:
				m_chosenParam.push_back("RAM");
				m_IphoneChosen.push_back(Iphone.getRam());
				m_SamsungChosen.push_back(Samsung.getRam());
				m_HuaweiChosen.push_back(Huawei.getRam());
				inUse.push_back(inVal);
				break;
			case 4:
				m_chosenParam.push_back("Price");
				m_IphoneChosen.push_back(Iphone.getPrice());
				m_SamsungChosen.push_back(Samsung.getPrice());
				m_HuaweiChosen.push_back(Huawei.getPrice());
				inUse.push_back(inVal);
				break;
			case 5:
				m_chosenParam.push_back("Performance");
				m_IphoneChosen.push_back(Iphone.getPerform());
				m_SamsungChosen.push_back(Samsung.getPerform());
				m_HuaweiChosen.push_back(Huawei.getPerform());
				inUse.push_back(inVal);
				break;
			case 6:
				m_chosenParam.push_back("Battery");
				m_IphoneChosen.push_back(Iphone.getBatt());
				m_SamsungChosen.push_back(Samsung.getBatt());
				m_HuaweiChosen.push_back(Huawei.getBatt());
				inUse.push_back(inVal);
				break;
			case 7:
				m_chosenParam.push_back("Camera");
				m_IphoneChosen.push_back(Iphone.getCam());
				m_SamsungChosen.push_back(Samsung.getCam());
				m_HuaweiChosen.push_back(Huawei.getCam());
				inUse.push_back(inVal);
				break;
			default:
				LogInputError();
				--i;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				break;
			}
		}
		
	}
}

void ChosenParam::printChosen()
{
	for (auto& i : m_chosenParam)
	{
		std::cout << i << ", ";
	}
	std::cout << std::endl;
}

std::vector<std::string> ChosenParam::getChosenParam() const { return m_chosenParam; }
std::vector<Param> ChosenParam::getIphoneParam() const { return m_IphoneChosen; }
std::vector<Param> ChosenParam::getSamsungParam()const { return m_SamsungChosen; }
std::vector<Param> ChosenParam::getHuaweiParam()const { return m_HuaweiChosen; }