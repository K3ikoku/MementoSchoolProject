#include "Memento.h"

Memento::Memento(const std::string line)
{
    m_line = line;
}

Memento::Memento()
{
}

std::string Memento::GetLine()
{
    return m_line;
}
