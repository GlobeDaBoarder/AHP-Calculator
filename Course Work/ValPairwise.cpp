#include "ValPairwise.h"

ValPair::ValPair(): ValTableBase()
{
}

ValPair::~ValPair()
{
}

void ValPair::printTable(ChosenParam& chosenparams, int& ind)
{
	ValTableBase::printTable(chosenparams, ind);
}

std::vector<std::vector<double>> ValPair::getContent() const { return m_content; }