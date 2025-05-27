#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, k;
    cin >> N >> k;
    
    vector<int> v;
    int num;
    for(int i=0; i<N; i++)
    {
        cin >> num;
        v.push_back(num);
    }
    
    sort(v.begin(), v.end(), greater<int>());
    
    cout << v[k-1];
    return 0;
}