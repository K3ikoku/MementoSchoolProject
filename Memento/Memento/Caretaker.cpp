#include "Caretaker.h"



Caretaker::Caretaker()
{
}


Caretaker::~Caretaker()
{
}

void Caretaker::saveState(Originator & originator)
{
	m_undoStack.push(originator.createMemento());
}

void Caretaker::undoState(Originator & originator)
{
	Memento* mem = m_undoStack.top();
	m_undoStack.pop();

	//Push to redo stack
	m_redoStack.push(originator.createMemento());

	//Revert to previous state
	originator.applyMemento(mem);
	delete mem;
}

void Caretaker::redoState(Originator & originator)
{
	Memento* mem = m_redoStack.top();
	m_redoStack.pop();

	//Push to undo stack
	m_undoStack.push(originator.createMemento());

	//Revert to previous state
	originator.applyMemento(mem);
	delete mem;
}
