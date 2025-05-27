#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    vector<int> v;
    int sum = 0;
    int num;
    for(int i=0; i<5; i++)
    {
        cin >> num;
        v.push_back(num);
        sum += num;
    }
    
    sort(v.begin(), v.end());
    
    cout << sum/5 << endl << v[2];
    
    return 0;
}