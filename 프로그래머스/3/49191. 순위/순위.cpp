#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    vector<vector<int>> dist(n+1, vector<int>(n+1));
    for(int i=0; i<results.size(); i++)
    {
        dist[results[i][0]][results[i][1]] = 1;
        dist[results[i][1]][results[i][0]] = -1;
    }
    
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            if(dist[i][k] <= 0) continue;
            for(int j=1; j<=n; j++)
            {
                if(dist[k][j] <= 0) continue;
                dist[i][j] = 1;
                dist[j][i] = -1;
            }
        }
    }
    
    for(int i=1; i<=n; i++)
    {
        bool Possible = true;
        for(int j=1; j<=n; j++)
        {
            if(i == j) continue;
            if(dist[i][j] == 0)
            {
                Possible = false;
                break;
            }
        }
        
        if(Possible)
            answer++;
    }
    return answer;
}