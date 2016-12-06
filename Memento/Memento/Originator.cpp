#include "Originator.h"
#include "Memento.h"
#include <stdio.h>



Originator::Originator():
	m_value("")
{
}

void Originator::SetValue(std::string value)
{
	m_value = value;
}

std::string Originator::GetValue()
{
	return m_value;
}

void Originator::ApplyMemento(Memento * memento)
{
	m_value = memento->GetValue();
}

Memento * Originator::CreateMemento()
{
	Memento* mem = new Memento();
	mem->SetValue(this->GetValue());

	return mem;
}
