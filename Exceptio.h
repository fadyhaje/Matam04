#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <exception>
#include <string>

class DeckFileInvalidSize :public std::exception
{
    public:
     DeckFileInvalidSize() : m_error_line("Deck File Error: Deck size is invalid")
     {
     }
     const char* what() const noexcept override 
     {
        return m_error_line.c_str(); 
    }
    private:
      std::string m_error_line;
};


class DeckFileFormatError :public std::exception
{
public:
    DeckFileFormatError(int line) : m_error_line("Deck File Error: File format error in line "+ std::to_string(line))
    {
    }
    const char* what() const noexcept override 
    {
        return m_error_line.c_str();
    }
    private:
      std::string m_error_line;

};

class DeckFileNotFound :public std::exception 
{
public:
    DeckFileNotFound() : m_error_line("Deck File Error: File not found")
    {
    }
    const char* what() const noexcept override
    {
        return  m_error_line.c_str();
    }
    private:
      std::string m_error_line;
};

#endif // EX4_EXCEPTIONS_H
