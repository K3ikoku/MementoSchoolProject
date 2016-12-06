#include "Caretaker.h"
#include <stdio.h>



Caretaker::Caretaker()
{
}


Caretaker::~Caretaker()
{
}

void Caretaker::SaveState(Originator & originator)
{
	m_undoStack.push_back(originator.CreateMemento());
}

void Caretaker::UndoState(Originator & originator)
{
	Memento* mem = m_undoStack.back();
	m_undoStack.pop_back();

	//Push to redo stack
	m_redoStack.push_back(originator.CreateMemento());

	//Revert to previous state
	originator.ApplyMemento(mem);
	delete mem;
}

void Caretaker::RedoState(Originator & originator)
{
	Memento* mem = m_redoStack.back();
	m_redoStack.pop_back();

	//Push to undo stack
	m_undoStack.push_back(originator.CreateMemento());

	//Revert to previous state
	originator.ApplyMemento(mem);
	delete mem;
}

void Caretaker::Print(Originator & originator)
{
	for each (Memento* mem in m_undoStack)
	{
		printf("%s", mem->GetValue());
	}
	printf("\n\n");
}
