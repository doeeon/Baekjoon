#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<int> A(N);
    vector<int> B(N);
    for(int i=0; i<N; i++)
        cin >> A[i];
    for(int i=0; i<N; i++)
        cin >> B[i];
        
    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());
    
    int answer = 0;
    for(int i=0; i<N; i++)
        answer += A[i]*B[i];
        
    cout << answer;

    return 0;
}