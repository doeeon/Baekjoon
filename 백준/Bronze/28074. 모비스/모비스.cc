#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    
    bool alpha[26] = {0};
    for(char c : str)
        alpha[c-'A'] = true;
    
    if(alpha['M'-'A'] && alpha['O'-'A'] && alpha['B'-'A'] && alpha['I'-'A'] && alpha['S'-'A'])
        cout << "YES";
    else
        cout << "NO";

    return 0;
}