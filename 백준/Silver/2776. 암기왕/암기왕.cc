#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    for(int t=0; t<T; t++)
    {
        
        int N, M;
        set<int> s;
        
        cin >> N;
        int num;
        for(int i=0; i<N; i++)
        {
            cin >> num;
            s.insert(num);
        }
        
        cin >> M;
        for(int i=0; i<M; i++)
        {
            cin >> num;
            if(s.find(num) != s.end())
                cout << "1\n";
            else
                cout << "0\n";
        }
    }

    return 0;
}