#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // cost, node
    
    visited[0] = true; // 시작 정점
    for(int i=0; i<costs.size(); i++)
    {
        if(costs[i][0] == 0)
            pq.push({costs[i][2], costs[i][1]});
        else if(costs[i][1] == 0)
            pq.push({costs[i][2], costs[i][0]});
    }
    
    while(!pq.empty())
    {
        int next_node = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if(visited[next_node])
            continue;
        
        answer += cost;
        visited[next_node] = true;
        
        for(int i=0; i<costs.size(); i++)
        {
            if(costs[i][0] == next_node)
                pq.push({costs[i][2], costs[i][1]});
            else if(costs[i][1] == next_node)
                pq.push({costs[i][2], costs[i][0]});
        }
    }
    
    return answer;
}