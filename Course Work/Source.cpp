#include <iostream>
#include "Phone.h"
#include "ChosenParam.h"
#include <fstream>
#include "PairwiseComp.h"
#include "Stand.h"


int main()
{
	//getting phone stats from files

	Phone Iphone;
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

		///  UI

	std::cout << "Weclome to AHP Method calculator! \n"
		"AHP (Analytic hierarchy process) is a technique for organizing a complicaed decission making process\n"
		"In the current Example 3 Phones are presented \n"
		"Choose important to you parameters and this calculator will give you a good option for you! \n";

	std::cout << std::endl << "Here are all the parameters of phones: " << std::endl << std::endl;
	std::cout << Iphone << Samsung << Huawei;

	//choosing parameters

	ChosenParam chosenParams;
	chosenParams.ChooseParams(Iphone, Samsung, Huawei);
	chosenParams.printChosen();

	//evaluation

	PairwiseComp PCTable;
	PCTable.AssessContent(chosenParams);


	//printing pairwise comparison of parameters
	PCTable.printTable(chosenParams);

	//Standardized matrix
	Stand stand(PCTable);
	stand.printTable(chosenParams);
}