#include "ValTableBase.h"

ValTableBase::ValTableBase()
{
	std::vector<double> temp(3, 0);
	for (int i = 0; i < 3; ++i)
	{
		m_content.push_back(temp);
	}
}