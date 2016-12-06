#pragma once
#include "Memento.h"
#include "Originator.h"
#include <vector>
class Caretaker
{
public:
	Caretaker();
	~Caretaker();

	void SaveState(Originator& originator);
	void UndoState(Originator& originator);
	void RedoState(Originator& originator);
	void Print(Originator& originator);

private:
	std::vector<Memento*> m_undoStack;
	std::vector<Memento*> m_redoStack;
};

