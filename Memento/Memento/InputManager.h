#pragma once
#include "Caretaker.h"
#include "Originator.h"
#include <string>


class InputManager
{
public:
	InputManager();
	~InputManager();

	void Loop();
	void ManageInput(Caretaker& caretaker, Originator& originator);

private:
	Caretaker* m_caretaker;
	Originator* m_originator;
	char m_write;
	std::string m_newLine;
};

