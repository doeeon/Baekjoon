#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    deque<pair<int, int>> dq;
    int num;
    for(int i=1; i<=N; i++)
    {
        cin >> num;
        dq.push_back({num, i}); //{num, index}
    }
    
    vector<int> answer;
    int next = 0;
    
    while(!dq.empty())
    {
        if(next >= 0)
        {
            for(int i=0; i<next-1; i++)
            {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            
            answer.push_back(dq.front().second);
            next = dq.front().first;
            dq.pop_front();
        }
        else
        {
            for(int i=0; i<-next-1; i++)
            {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            answer.push_back(dq.back().second);
            next = dq.back().first;
            dq.pop_back();
        }
    }
    
    for(auto a : answer)
        cout << a << ' ';
    
    return 0;
}