#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    string str;
    unordered_set<string> s;
    for(int i=0; i<N; i++)
    {
        cin >> str;
        s.insert(str);
    }
    
    int answer = 0;
    for(int i=0; i<M; i++)
    {
        cin >> str;
        if(s.find(str) != s.end())
            answer++;
    }
    
    cout << answer;
    return 0;
}