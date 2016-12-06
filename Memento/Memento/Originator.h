#pragma once
#include <string>
class Memento;
class Originator
{
public:
	Originator();
	
	void SetValue(std::string value);
	std::string GetValue();
	void ApplyMemento(Memento* memento);

	Memento* CreateMemento();
	

private:
	std::string m_value;
};

