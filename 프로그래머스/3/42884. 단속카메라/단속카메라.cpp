#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
    if(a[1] == b[1])
        return a[0] < b[0];
    else
        return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end(), cmp);
    
    vector<bool> visited(routes.size(), false);  
    for(int i=0; i<routes.size(); i++)
    {
        if(visited[i])
            continue;
        
        visited[i] = true;
        answer++;        
        for(int j=i+1; j<routes.size(); j++)
        {
            if(routes[j][0] <= routes[i][1] && routes[j][1] >= routes[i][1])
                visited[j] = true;
            else
            {
                i = j-1;
                break;
            }
        }
    }
    return answer;
}