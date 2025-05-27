#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    set<int> s;
    int num;
    for(int i=0; i<N; i++)
    {
        cin >> num;
        s.insert(num);
    }
    
    for(auto iter = s.begin(); iter!=s.end(); iter++)
        cout << *iter << '\n';
        
    return 0;
}