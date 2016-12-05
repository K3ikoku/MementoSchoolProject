#pragma once
class Memento;
class Originator
{
public:
	Originator();
	
	void setValue(int value) { m_value = value; }
	int getValue() { return m_value; }
	void applyMemento(Memento* memento);

	Memento* createMemento();
	

private:
	int m_value;
};

