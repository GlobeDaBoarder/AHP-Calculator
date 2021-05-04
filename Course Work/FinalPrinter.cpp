#include"FinalPrinter.h"
#include <sstream>
#include <iostream>
#include <iomanip>

void FinalPrinter::printSS(std::stringstream& ss, bool border)
{
	std::cout << std::setw(20) << std::left << ss.str() << ((border) ? '|' : ' ');
}

void FinalPrinter::printInFormat(std::string& s, bool border)
{
	std::stringstream ss;
	ss << ' '<<  s;
	printSS(ss, border);
}

void FinalPrinter::printInFormat(std::string s, bool border)
{
	std::stringstream ss;
	ss << ' ' << s;
	printSS(ss, border);
}

void FinalPrinter::printInFormat(double& num, bool border)
{
	std::stringstream ss;
	ss << ' '<<  std::setprecision(7) << num;
	printSS(ss, border);
}

void FinalPrinter::printInFormat(char ch)
{
	std::stringstream ss;
	ss << ' ' << ch;
	printSS(ss);
}

void FinalPrinter::printLine(bool border)
{
	std::cout << std::endl;
	for (int i = 0; i < 7; ++i)
	{
		std::cout << std::setw(20) << std::setfill('_')  << '_' <<((border || (i == 6)) ? '|' : '_');
	}
	std::cout << std::endl;
}