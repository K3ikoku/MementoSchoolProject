#pragma once
#include <string>

class Memento
{
public:
	Memento();

	void SetValue(std::string value);
	std::string GetValue();


private:
	std::string m_value;
};

