#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <queue>
using namespace std;

vector<vector<int>> Rotate(vector<vector<int>>& shape)
{
    // 시계방향으로 90도 회전
    int w = shape.size();
    int h = shape[0].size();
    
    vector<vector<int>> result(h, vector<int>(w, 0));
    
    for(int i=0; i<h; i++)
        for(int j=0; j<w; j++)
            result[i][j] = shape[w-j-1][i];
    
    return result;
}

bool Comparison(vector<vector<int>>& blank, vector<vector<int>>& puzzle)
{
    // 회전하면서 완전탐색 비교 후 return
    bool result = true;
    vector<vector<int>> tmp(puzzle);
    for(int t=0; t<4; t++)
    {
        if(t > 0)
        {
            tmp = Rotate(tmp);
            result = true;
        }
        
        if(blank.size() != tmp.size() || blank[0].size() != tmp[0].size())
            result = false;

        for(int i=0; i<blank.size() && result; i++)
            for(int j=0; j<blank[0].size() && result; j++)
                if(blank[i][j] == tmp[i][j])
                    result = false;

        if(result)
            return result;
    }
    
    return result;
}

void Add(vector<int>& info, vector<vector<int>>& map, vector<vector<vector<int>>>& storage)
{
    // map에서 block 추출해서 storage에 push
    // info = {min_y, min_x, max_y, max_x}
    
    vector<vector<int>> block(info[2]-info[0]+1, vector<int>(info[3]-info[1]+1, 0));
    
    for(int i=info[0]; i<=info[2]; i++)
        for(int j=info[1]; j<=info[3]; j++)
            block[i-info[0]][j-info[1]] = map[i][j];
    
    storage.push_back(block);
}

void BFS(int y, int x, int type, vector<vector<int>>& map, vector<vector<bool>>& visited, vector<vector<vector<int>>>& result)
{
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };
	vector<int> cordi = {y, x, y, x}; //{min_y, min_x, max_y, max_x}
	queue<pair<int, int>> q;

	q.push({ y, x });
	visited[y][x] = true;

	while (!q.empty())
	{
		for (int i = 0; i < 4; i++)
		{
			int nx = q.front().second + dx[i];
			int ny = q.front().first + dy[i];

			if (nx >= 0 && nx < map[0].size() && ny >= 0 && ny < map.size() && !visited[ny][nx] && map[ny][nx] == type)
			{
				q.push({ ny, nx });
				visited[ny][nx] = true;

				cordi[0] = min(cordi[0], ny);
				cordi[1] = min(cordi[1], nx);
				cordi[2] = max(cordi[2], ny);
				cordi[3] = max(cordi[3], nx);
			}
		}

		q.pop();
	}

	Add(cordi, map, result);

}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    int N = game_board.size();
    
    // BFS로 game_board에서 blank, table에서 puzzle 찾기
    vector<vector<vector<int>>> blanks;
    vector<vector<vector<int>>> puzzles;
    
    vector<vector<bool>> g_visited(N, vector<bool>(N, false));
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if(game_board[i][j] == 0 && !g_visited[i][j])
                BFS(i, j, 0, game_board, g_visited, blanks);
    
    vector<vector<bool>> t_visited(N, vector<bool>(N, false));
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if(table[i][j] == 1 && !t_visited[i][j])
                BFS(i, j, 1, table, t_visited, puzzles);

    // puzzles과 blanks 비교 후 일치하면 삭제
    for(int i=0; i<puzzles.size(); i++)
        for(int j=0; j<blanks.size(); j++)
            if(Comparison(blanks[j], puzzles[i]))
            {
                for(int a=0; a<puzzles[i].size(); a++)
                    for(int b=0; b<puzzles[i][a].size(); b++)
                        if(puzzles[i][a][b])
                            answer++;
  
                blanks.erase(blanks.begin() + j);
                break;
            }

    return answer;
}