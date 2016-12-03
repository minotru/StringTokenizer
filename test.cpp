#include <string>
#include <iostream>
#include <vector>
#include <cstring>

#include "StringTokenizer/StringTokenizer.h"

using namespace std;

int main()
{
    string s = ".aaa bb,.,a.,.,so ";
    StringTokenizer st(s, std::string(" ,."), true);
    cout << s << '#' << endl;
    while (st.hasMoreTokens())
        cout << st.nextToken() << '#' << endl;

    vector<string> v = st.tokensAsVector();
    for (size_t i = 0; i < v.size(); i++)
        cout << v[i] << '#' << endl;

    return 0;
}
