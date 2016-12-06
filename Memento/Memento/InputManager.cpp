#include "InputManager.h"
#include <stdio.h>



InputManager::InputManager():
	m_originator(nullptr), m_caretaker(nullptr),
	m_write('n'), m_newLine("")
{

}


InputManager::~InputManager()
{
}

void InputManager::Loop()
{
		m_originator = new Originator;
		m_caretaker = new Caretaker;

		while (m_originator->GetValue == "" || m_write != 'n')
		{
			printf("Write what you wish\n");
			scanf("%s", m_newLine);
			
			m_originator->SetValue(m_newLine);
			m_caretaker->Print(*m_originator);

			ManageInput(*m_caretaker, *m_originator);


		}


	
}

void InputManager::ManageInput(Caretaker& caretaker, Originator& originator)
{
	char m_input;
	printf("Are you satisfied with that?\n");
	printf("press: \n c to continue \n u to undo the last line \n r to redo the last thing you removed \n");
	scanf("%c", m_input);

	if (m_input == 'c' || m_input == 'u' || m_input == 'r')
	{
		switch (m_input)
		{
		case 'c':
			break;
		case 'u':
			caretaker.UndoState(originator);
		case 'r':
			caretaker.RedoState(originator);
		default:
			printf("You entered the wrong input please try again");
			ManageInput(caretaker, originator);
		}
	}
}
