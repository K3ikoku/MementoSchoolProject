#pragma once
class Memento
{
public:
	Memento();

	void setValue(int value) { m_value = value; }
	int getValue() { return m_value; }


private:
	int m_value;
};

