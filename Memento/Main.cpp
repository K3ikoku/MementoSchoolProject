#include <sstream>
#include <iostream>
#include "Originator.h"


int main()
{
    Originator* m_originator = Originator::GetInstance();

    std::string m_input = "y";

    printf(" Hello there enter a new line of text and save it for later!\n");
    printf("To remove a line you have written type 'undo' and hit enter\n");
    printf("If you regret removing a line type 'redo' and hit enter\n");
    printf("If you want to write out all the lines you have written so far type 'print' and hit enter");
    printf("Type 'exit' to exit the application\n");
    printf("IMPORTANT: All commands are case sensetive\n\n");
    printf("\n You can now start writing messages or notes\n");
    while (m_input != "exit")
    {
        std::getline(std::cin, m_input);
        m_input = m_originator->AddNewLine(m_input);
    }

    return 0;
}