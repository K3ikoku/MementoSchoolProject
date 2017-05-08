#include "Originator.h"

Originator* Originator::m_originator = nullptr;

Originator * Originator::GetInstance()
{
    if (m_originator == nullptr)
        m_originator = new Originator();

    return m_originator;
}

Originator::Originator()
{
}

std::string Originator::AddNewLine(const std::string line)
{
    if (line == "undo")
        Undo();
    else if (line == "redo")
        Redo();
    else if (line == "print")
        Print();
    else if (line == "exit")
        return ("exit");
    else
    {
        m_log.push(new Memento(line));
        printf("Saving log \n");
    }
    return "\n";
}

void Originator::Print()
{
    if (m_log.size() > 0)
    {
        for (int i = 0; i < m_log.size(); i++)
        {
            std::string line = m_log.top()->GetLine();
            m_log.pop();
            m_tempStack.push(new Memento(line));
            i--;
        }

        for (int i = 0; i < m_tempStack.size(); i++)
        {
            std::string line = m_tempStack.top()->GetLine();
            m_tempStack.pop();
            m_log.push(new Memento(line));
            printf("%s", line.c_str());
            i--;
        }
        printf("\n");
    }
    else
    {
        printf("You have yet to write any lines to print\n");
    }
}

std::string Originator::Undo()
{
    if (m_log.size() > 0)
    {
        std::string line = m_log.top()->GetLine();
        m_log.pop();
        m_redoStack.push(new Memento(line));
        printf("Removed follow line: %s \n" , line.c_str());
        return line;
    }

    else
    {
        printf("You have yet to write any lines. \n Please write a line. \n");
        return "";
    }
}

std::string Originator::Redo()
{
    if (m_redoStack.size() > 0)
    {
        std::string line = m_redoStack.top()->GetLine();
        m_redoStack.pop();
        m_log.push(new Memento(line));
        printf("The following line has now been put back into your log: %s \n", line.c_str());
        return line;
    }
    else
    {
        printf("You have nothing to redo, you need to remove a line to complete this action\n");
        return "";
    }
}
