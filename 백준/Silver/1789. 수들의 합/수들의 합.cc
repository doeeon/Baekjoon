#include <iostream>

using namespace std;

int main()
{
    long long S;
    cin >> S;
    
    long long N = 1;
    while(N*(N+1)/2 <= S)
        N++;

    cout << N-1;
    return 0;
}