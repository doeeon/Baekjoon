#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    string str;
    int answer = 0;
    for(int i=0; i<N; i++)
    {
        cin >> str;
        
        vector<bool> alpha(26, false);
        bool IsGroupWord = true;
        for(int i=0; i<str.size(); i++)
        {
            if(alpha[str[i]-'a'] == false)
                alpha[str[i]-'a'] = true;
            else
            {
                if(str[i] == str[i-1]) continue;
                IsGroupWord = false;
                break;
            }
        }
        
        if(IsGroupWord)
            answer++;
    }

    cout << answer;
    return 0;
}