#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    
    set<int> A;
    set<int> B;
    
    int num;
    for(int i=0; i<N; i++)
    {
        cin >> num;
        A.insert(num);
    }
    
    for(int i=0; i<M; i++)
    {
        cin >> num;
        B.insert(num);
    }
    
    int answer = 0;
    for(auto n : A)
        if(B.find(n) == B.end())
            answer++;
    
    for(auto n : B)
        if(A.find(n) == A.end())
            answer++;
    
    cout << answer;
    return 0;
}