#ifndef STRING_TOKENIZER_H
#define STRING_TOKENIZER_H

//This class is c++ implementation of Java StringTokenizer class.
//By Simon Karasik, 2016, senich10@mail.ru
//GitHub: https://github.com/minotru/StringTokenizer

#include <string>
#include <vector>

class StringTokenizer
{
    public:
        StringTokenizer(const std::string& str, const std::string& delim,
                        bool returnDelims = false);
        ~StringTokenizer();

        int countTokens();
        bool hasMoreTokens();
        std::string nextToken();
        std::string nextToken(const std::string& delim);
        std::vector<std::string> tokensAsVector();

        static const std::string DEFAULT_DELIM /*= " \t\n\r\f"*/;

    private:
        std::string m_str, m_delim;
        size_t m_pos;
        bool m_returnDelims, m_skipEmpty;

        bool isDelim(char c);
        size_t nextTokenPos(size_t searchFrom, size_t& begin);
};

#endif // STRING_TOKENIZER_H
