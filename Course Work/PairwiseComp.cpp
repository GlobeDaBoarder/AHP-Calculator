#include "PairwiseComp.h"
#include "ChosenParam.h"


//private methods:

void PairwiseComp::CountSum()
{
	for (int i = 0; i < 5; ++i)
	{
		double tempSum = 0;
		for (int j = 0; j < 5; ++j)
		{
			tempSum += m_content[j][i];
		}
		m_sum.push_back(tempSum);
	}
}

double PairwiseComp::ReadEvaluation() const
{
	double grade = 0;
	std::cin >> grade;
	if (grade <= 9 && grade >= 1 / 9 && grade != 0)
	{
		return grade;
	}

	std::cout << "[WRONG INPUT]" << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return ReadEvaluation();
}

//public methods:


PairwiseComp::PairwiseComp() : TableBase()
{
}

PairwiseComp::~PairwiseComp() 
{
}

void PairwiseComp::AssessContent(ChosenParam& chosenParams)
{
	std::cout << std::endl << "Evaluate each CRITERIA'S IMPORTANCE with relation to others from 1/9 to 9 \n"
		"1 -- equally important \t 3 -- moderate \t 5 -- strong \t 7 - very strong \t 9 -- extreme \n\n";

	double grade = 0;
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (i == j)
			{
				m_content[i][j] = 1;
			}
			else if (j < i)
			{
				m_content[i][j] = 1 / m_content[j][i];
			}
			else
			{
				std::cout << "Importance of " << chosenParams.getChosenParam()[i] << '/' << chosenParams.getChosenParam()[j] << "= ";
				grade = ReadEvaluation();

				m_content[i][j] = grade;
			}
		}
	}

	CountSum();
}

void PairwiseComp::printTable(ChosenParam& chosenParams) 
{
	std::cout << "\n\nPairwise comparison of the parameters (SUM is a sum of all element if s COLUMN: \n";

	TableBase::printTable(chosenParams);

	printInFormat("SUM");
	for (double& i : m_sum)
	{
		printInFormat(i);
	}
	printLine();
}

std::vector<std::vector<double>> PairwiseComp::getContent() const { return m_content; }
std::vector<double> PairwiseComp::getSum() const { return m_sum; }
