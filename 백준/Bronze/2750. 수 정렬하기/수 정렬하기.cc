#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    vector<int> v;
    int num;
    for(int i=0; i<N; i++)
    {
        cin >> num;
        v.push_back(num);
    }
    
    sort(v.begin(), v.end());
    
    for(int i=0; i<v.size(); i++)
        cout << v[i] << endl;
    return 0;
}