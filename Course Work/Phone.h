#pragma once
#include <string>
#include "IPhone.h"
#include "Param.h"
class Phone : public IPhone
{
private:

	//list??
	std::string m_name;
	Param m_display{ "Display" };
	Param m_memSize{ "Memory Size" };
	Param m_ram{ "RAM" };
	Param m_price{ "Price" };
	Param m_perform{ "Performance " };
	Param m_batt{ "Battery" };
	Param m_cam{ "Camera" };

	std::ifstream& readParams(std::ifstream& input) override;
	std::ostream& printPhone(std::ostream& output)const override;

public:
	//Phone();
	Phone();
	~Phone();

	const std::string& getName() const override;

	const Param getDisplay() const override;
	const Param getMemSize() const override;
	const Param getRam() const override;
	const Param getPrice() const override;
	const Param getPerform() const override;
	const Param getBatt() const override;
	const Param getCam() const override;
	
	friend std::ifstream& operator>> (std::ifstream& input, Phone& phone);
	friend std::ostream& operator<< (std::ostream& output, Phone& phone);
};

