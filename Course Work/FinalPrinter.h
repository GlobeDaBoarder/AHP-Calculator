#pragma once
#include <string>

class FinalPrinter
{
private:
	void printSS(std::stringstream& ss, bool border = false);

protected:

	void printInFormat(std::string s, bool border = true);
	void printInFormat(double num, bool border = true);
	void printInFormat(char ch);

	void printLine(bool border = false);

};