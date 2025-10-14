#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

bool vcmp(vector<int> a, vector<int> b)
{
    if(a[1] == b[1])
    {
        if(a[0] == b[0])
            return a[2] < b[2];
        return a[0] < b[0];
    }
    return a[1] < b[1];
}

struct cmp{
    bool operator() (const vector<int>& a, const vector<int>& b) const
    {
        if(a[2] != b[2])
            return a[2] > b[2];
        if(a[1] != b[1])
            return a[1] > b[1];
        if(a[0] != b[0])
            return a[0] > b[0];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    vector<vector<int>> arr;
    for(int i=0; i<jobs.size(); i++)
        arr.push_back({i, jobs[i][0], jobs[i][1]});

    sort(arr.begin(), arr.end(), vcmp);
    
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    pq.push(arr[0]);
    int last = 0;
    for(int i=1; i<arr.size(); i++)
    {
        if(arr[0][1] == arr[i][1])
        {
            pq.push(arr[i]);
            last = i;
        }
        else
            break;
    }
    int time = pq.top()[1];
    
    vector<pair<int, int>> completed;
    while(!pq.empty())
    {
        completed.push_back({pq.top()[1], time+pq.top()[2]});
        
        time += pq.top()[2];
        pq.pop();
        for(last += 1;last < arr.size(); last++)
        {
            if(time >= arr[last][1])
                pq.push(arr[last]);
            else
            {
                last--;
                break;
            }
        }
        
        if(last > arr.size())
            last = arr.size();
        
        if(pq.empty() && last < arr.size())
        {
            pq.push(arr[last+1]);
            time = arr[last+1][1];
            last++;
        }
    }
    
    int sum = 0;
    for(int i=0; i<completed.size(); i++)
        sum += completed[i].second - completed[i].first;
    
    answer = sum / completed.size();
    
    return answer;
}