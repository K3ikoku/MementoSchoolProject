#pragma once
#include "Memento.h"
#include "Originator.h"
#include <stack>
class Caretaker
{
public:
	Caretaker();
	~Caretaker();

	void saveState(Originator& originator);
	void undoState(Originator& originator);
	void redoState(Originator& originator);

private:
	std::stack<Memento*> m_undoStack;
	std::stack<Memento*> m_redoStack;
};

