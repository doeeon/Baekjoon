#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    for(int t=0; t<T; t++)
    {
        vector<int> arr(10);
        for(int i=0; i<10; i++)
            cin >> arr[i];
        
        sort(arr.rbegin(), arr.rend());
        
        cout << arr[2] << '\n';
    }
    return 0;
}