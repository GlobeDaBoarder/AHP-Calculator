#include "Inconst.h"

//private

void Inconst::printweights()
{
	printInFormat("WEIGHTS");
	for (auto& i : m_weightscopy)
	{
		printInFormat(i, '%');
	}
	printLine();
}

//public

Inconst::Inconst(PairwiseComp& PCTable, Stand& stand) : TableBase()
{
	m_weightscopy = stand.getWeights();
	for (int i = 0; i < 5; ++i)
	{
		double tempSum = 0;
		for (int j = 0; j < 5; ++j)
		{
			m_content[i][j] = PCTable.getContent()[i][j] * m_weightscopy[i];
			tempSum += m_content[i][j];
		}

		m_weightsum.push_back(tempSum);
		m_lambda.push_back(m_weightsum[i] / m_weightscopy[i]);
	}
}

Inconst::~Inconst()
{
}

void Inconst::printTable(ChosenParam& chosenparams)
{
	std::cout << "\n\nConsistency matrix\n";

	printweights();
	TableBase::printTable(chosenparams);

	std::cout << "Weight represents average of sum of every ROW" << std::endl;
}

std::vector<std::vector<double>> Inconst::getContent() const { return m_content; }