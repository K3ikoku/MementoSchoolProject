#include "Memento.h"
#include <stdio.h>
#include <string>



Memento::Memento():
	m_value("")
{
}

void Memento::SetValue(std::string value)
{
	m_value = value;
}

std::string Memento::GetValue()
{
	return m_value;
}
