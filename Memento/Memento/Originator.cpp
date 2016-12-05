#include "Originator.h"
#include "Memento.h"



Originator::Originator():
	m_value(0)
{
}

void Originator::applyMemento(Memento * memento)
{
	m_value = memento->getValue();
}

Memento * Originator::createMemento()
{
	Memento* mem = new Memento();
	mem->setValue(this->getValue());

	return mem;
}
