//StringTokenizer.cpp
//By Simon Karasik, 2016, senich10@mail.ru
//GitHub: https://github.com/minotru/StringTokenizer

#include "StringTokenizer.h"
#include <string>
#include <vector>

const std::string StringTokenizer::DEFAULT_DELIM = " \t\n\r\f";

StringTokenizer::StringTokenizer(const std::string& str,
                                 const std::string& delim = DEFAULT_DELIM,
                                 bool returnDelims): m_str(str), m_delim(delim)
{
    m_pos = 0;
    m_returnDelims = returnDelims;
}

StringTokenizer::~StringTokenizer()
{
    //empty
}

int StringTokenizer::countTokens()
{
    size_t tokCnt = 0, tokLen, start = m_pos;
    while ((start = nextTokenPos(start, tokLen)) != std::string::npos)
    {
        start += tokLen;
        tokCnt++;
    }
    return tokCnt;
}

bool StringTokenizer::hasMoreTokens()
{
    size_t tokLen;
    return nextTokenPos(m_pos, tokLen) != std::string::npos;
}

std::string StringTokenizer::nextToken()
{
    if (!hasMoreTokens())
        return std::string("");

    std::string tok;
    size_t start, tokLen;

    start = nextTokenPos(m_pos, tokLen);
    tok = m_str.substr(start, tokLen);
    m_pos = start + tokLen;

    return tok;
}

std::string StringTokenizer::nextToken(const std::string& delim)
{
    m_delim = delim;
    return nextToken();
}

std::vector<std::string> StringTokenizer::tokensAsVector()
{
    std::vector<std::string> tokens;
    StringTokenizer st(m_str, m_delim, m_returnDelims);
    while (st.hasMoreTokens())
        tokens.push_back(st.nextToken());

    return tokens;
}


bool StringTokenizer::isDelim(char c)
{
    return m_delim.find(c) != std::string::npos;
}

//!@return The position of the token beginning or std::string::npos, if no token found.
size_t StringTokenizer::nextTokenPos(size_t searchFrom, size_t& tokLen)
{
    size_t charPos = m_str.find_first_not_of(m_delim, searchFrom),
           delimPos = m_str.find_first_of(m_delim, searchFrom);

    if (delimPos == searchFrom && m_returnDelims)
    {
        tokLen = 1;
        return delimPos;
    }
    else if (charPos != std::string::npos)
    {
        delimPos = m_str.find_first_of(m_delim, charPos);
        tokLen = std::min(delimPos - charPos, m_str.length() - charPos);
        return charPos;
    }
    else
        return std::string::npos;
}
