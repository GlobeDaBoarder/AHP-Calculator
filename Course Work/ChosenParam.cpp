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

void ChosenParam::ChooseParams(std::vector<Phone>& phones)
{
	for (int i = 0; i < 3; ++i)
	{
		Val temp;
		m_chosenValues.push_back(temp);
	}

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

				for (int i = 0; i < 3; ++i)
				{
					m_chosenValues[i].phoneName = phones[i].getName();
					m_chosenValues[i].stats.push_back(phones[i].getDisplay());
				}

				inUse.push_back(inVal);
				break;
			case 2:
				m_chosenParam.push_back("Memory size");

				for (int i = 0; i < 3; ++i)
				{
					m_chosenValues[i].phoneName = phones[i].getName();
					m_chosenValues[i].stats.push_back(phones[i].getMemSize());
				}

				inUse.push_back(inVal);
				break;
			case 3:
				m_chosenParam.push_back("RAM");

				for (int i = 0; i < 3; ++i)
				{
					m_chosenValues[i].phoneName = phones[i].getName();
					m_chosenValues[i].stats.push_back(phones[i].getRam());
				}

				inUse.push_back(inVal);
				break;
			case 4:
				m_chosenParam.push_back("Price");

				for (int i = 0; i < 3; ++i)
				{
					m_chosenValues[i].phoneName = phones[i].getName();
					m_chosenValues[i].stats.push_back(phones[i].getPrice());
				}

				inUse.push_back(inVal);
				break;
			case 5:
				m_chosenParam.push_back("Performance");

				for (int i = 0; i < 3; ++i)
				{
					m_chosenValues[i].phoneName = phones[i].getName();
					m_chosenValues[i].stats.push_back(phones[i].getPerform());
				}

				inUse.push_back(inVal);
				break;
			case 6:
				m_chosenParam.push_back("Battery");

				for (int i = 0; i < 3; ++i)
				{
					m_chosenValues[i].phoneName = phones[i].getName();
					m_chosenValues[i].stats.push_back(phones[i].getBatt());
				}

				inUse.push_back(inVal);
				break;
			case 7:
				m_chosenParam.push_back("Camera");

				for (int i = 0; i < 3; ++i)
				{
					m_chosenValues[i].phoneName = phones[i].getName();
					m_chosenValues[i].stats.push_back(phones[i].getCam());
				}

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
std::vector<Val> ChosenParam::getChosenValues() const { return m_chosenValues; }