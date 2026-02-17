#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<int> rope(N);
    for(int i=0; i<N; i++)
        cin >> rope[i];
        
    sort(rope.begin(), rope.end());
    
    int answer = 0;
    for(int i=0; i<N; i++)
        answer = max(answer, rope[i]*(N-i));
    
    cout << answer;

    return 0;
}