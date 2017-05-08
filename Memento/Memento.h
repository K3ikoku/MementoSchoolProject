#pragma once
#include <string>
class Memento
{
public:
    Memento(const std::string line);
    Memento();

    std::string GetLine();

private:
    std::string m_line;
};

