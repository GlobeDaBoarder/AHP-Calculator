#include <iostream>
#include "Phone.h"
#include "ChosenParam.h"
#include <fstream>
#include "PairwiseComp.h"
#include "Stand.h"
#include "Inconsist.h"

void StartCalculations()
{
	//getting phone stats from files

	std::vector<Phone> phones(3);
	
	std::ifstream infile;

	infile.open(".\\inputfiles\\Phone1.txt");
	infile >> phones[0];
	infile.close();

	infile.open(".\\inputfiles\\Phone2.txt");
	infile >> phones[1];
	infile.close();

	infile.open(".\\inputfiles\\Phone3.txt");
	infile >> phones[2];
	infile.close();

	std::cout << std::endl << "Here are all the parameters of phones: " << std::endl << std::endl;
	for (auto& i : phones)
	{
		std::cout << i;
	}

	/*Phone Iphone;
	std::ifstream IphoneFile(".\\inputfiles\\IphoneParams.txt");
	IphoneFile >> Iphone;
	IphoneFile.close();

	Phone Samsung;
	std::ifstream SamsungFile(".\\inputfiles\\SamsungParams.txt");
	SamsungFile >> Samsung;
	SamsungFile.close();

	Phone Huawei;
	std::ifstream HuaweiFile(".\\inputfiles\\HuaweiParams.txt");
	HuaweiFile >> Huawei;
	HuaweiFile.close();
	std::cout << std::endl << "Here are all the parameters of phones: " << std::endl << std::endl;
	std::cout << Iphone << Samsung << Huawei;*/

	//choosing parameters

	ChosenParam chosenParams;
	chosenParams.ChooseParams(phones);
	chosenParams.printChosen();

	//evaluation

	PairwiseComp PCTable;
	PCTable.AssessContent(chosenParams);


	//printing pairwise comparison of parameters

	PCTable.printTable(chosenParams);

	//Standardized matrix

	Stand stand(PCTable);
	stand.printTable(chosenParams);

	//inconsist 

	Inconst inconst(PCTable, stand);
	inconst.printTable(chosenParams);

	const double inconsistency = inconst.getInconsis();

	if (inconsistency < 0.1)
	{
		std::cout << "Inconsistency is less than 10%. Great job! Let's continue our calculations\n\n ";
	}
	else
	{
		std::cout << "Your criteria evaluations are not consistent! Try imputing more logical and consistent evaluations! \n\n";
		return;
	}

	std::cout << "Calculations are finished! You can try to do"
		"more calculations with different evaluations or quit the calculator \n\n";

}

int main()
{
		///  UI

	std::cout << "Weclome to AHP Method calculator! \n"
		"AHP (Analytic hierarchy process) is a technique for organizing a complicaed decission making process\n"
		"In the current Example 3 Phones are presented \n"
		"Choose important to you parameters and this calculator will give you a good option for you! \n";

	char ControlChar = ' ';

	while (true)
	{
		std::cout <<"Press 's' ro start evaluating and calculating \n"
			"Press 'q' to quit calculator \n";
		std::cin >> ControlChar;

		switch (ControlChar)
		{
		case 's':
			StartCalculations();
			break;
		case 'q':
			exit(0);
		default:
			std::cout << "[WRONG INPUT] \n";
		}
	}
	

	
}