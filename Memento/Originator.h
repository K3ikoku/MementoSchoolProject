#pragma once
#include <stack>
#include <iostream>
#include "Memento.h"

class Originator
{
public:
    static Originator* GetInstance();



    std::string AddNewLine(const std::string line);

private:
    static Originator* m_originator;

    void Print();
    std::string Undo();
    std::string Redo();

    std::stack<Memento*> m_log;
    std::stack<Memento*> m_redoStack;
    std::stack<Memento*> m_tempStack;

    Originator();
};

