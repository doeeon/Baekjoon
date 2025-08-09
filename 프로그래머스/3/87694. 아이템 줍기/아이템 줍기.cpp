#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

bool IsOutside(vector<vector<int>>& rectangle, int cy, int cx, int ny, int nx)
{
    for(int i=0; i<rectangle.size(); i++)
        if((cx+nx) > 2*rectangle[i][0] && (cx+nx) < 2*rectangle[i][2] && (cy+ny) > 2*rectangle[i][1] && (cy+ny) < 2*rectangle[i][3])
            return false;
    
    return true;
}

bool IsBorder(vector<vector<int>>& rectangle, int cy, int cx, int ny, int nx)
{
    if(IsOutside(rectangle, cy, cx, ny, nx))
    {
        for(int i=0; i<rectangle.size(); i++)
        {
            if(((cx+nx) == 2*rectangle[i][0] || (cx+nx) == 2*rectangle[i][2]) && (cy+ny) > 2*rectangle[i][1] && (cy+ny) < 2*rectangle[i][3])
                return true;
            else if(((cy+ny) == 2*rectangle[i][1] || (cy+ny) == 2*rectangle[i][3]) && (cx+nx) > 2*rectangle[i][0] && (cx+nx) < 2*rectangle[i][2])
                return true;
        }
    }
    return false;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    
    vector<vector<bool>> visited(60, vector<bool>(60, false));
    queue<pair<int, int>> q;
    queue<pair<int, int>> empty;
    
    q.push({characterY, characterX});
    visited[characterY][characterX] = 1;
    
    while(!q.empty())
    {
        int size = q.size();
        
        for(int i=0; i<size; i++)
        {
            int curx = q.front().second;
            int cury = q.front().first;
            q.pop();
            
            if(curx == itemX && cury == itemY)
                return answer;
            
            for(int j=0; j<4; j++)
            {
                int nx = curx + dx[j];
                int ny = cury + dy[j];
                
                if(!visited[ny][nx] && IsBorder(rectangle, cury, curx, ny, nx))
                {
                    q.push({ny, nx});
                    visited[ny][nx] = true;
                }
            }
        }
        answer++;
    }
    return answer;
}