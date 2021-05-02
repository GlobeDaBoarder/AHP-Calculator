#include "Phone.h"
#include <iostream>
Phone::Phone()
{
}

Phone::~Phone()
{
}

const std::string& Phone::getName() const { return m_name; }

const Param Phone::getDisplay() const { return m_display; }
const Param Phone::getMemSize() const { return m_memSize; }
const Param Phone::getRam() const { return m_ram; }
const Param Phone::getPrice() const { return m_price; }
const Param Phone::getPerform() const { return m_perform; }
const Param Phone::getBatt() const { return m_batt; }
const Param Phone::getCam() const { return m_cam; }

std::ifstream& Phone::readParams(std::ifstream& input)
{
	input >> this->m_name;
	input >> this->m_display.value;
	input >> this->m_memSize.value;
	input >> this->m_ram.value;
	input >> this->m_price.value;
	input >> this->m_perform.value;
	input >> this->m_batt.value;
	input >> this->m_cam.value;
	return input;
}

std::ifstream& operator>>(std::ifstream& input, Phone& phone)
{
	return phone.readParams(input);
}


std::ostream& Phone::printPhone(std::ostream& output) const
{
	output << this->m_name << std::endl;
	output << this->m_display;
	output << this->m_memSize;
	output << this->m_ram;
	output << this->m_price;
	output << this->m_perform;
	output << this->m_batt;
	output << this->m_cam;
	output << std::endl << std::endl;
	return output;
}

std::ostream& operator<<(std::ostream& output, Phone& phone)
{
	return phone.printPhone(output);
}
