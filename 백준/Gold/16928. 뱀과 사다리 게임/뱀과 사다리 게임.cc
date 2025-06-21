#include <iostream>
#include <map>
#include <queue>

using namespace std;

int BFS(map<int, int>& jump)
{
	int depth = 0;
	queue<int> q;
	vector<bool> visited(101, false);

	q.push(1);
	visited[1] = true;

	while (!q.empty())
	{
		depth++;
		int size = q.size();

		for (int i = 0; i < size; i++)
		{
			for (int j = 1; j <= 6; j++)
			{
				int next = q.front() + j;
				if (jump.find(next) != jump.end())
					next = jump[next];

				if (next == 100)
					return depth;

				if (!visited[next])
				{
					q.push(next);
					visited[next] = true;
				}
			}
			q.pop();
		}
	}

	return depth;
}

int main() {
	int N, M;
	cin >> N >> M;

	int a, b;
	map<int, int> jump;
	for (int i = 0; i < N+M; i++)
	{
		cin >> a >> b;
		jump[a] = b;
	}

	int answer = BFS(jump);
	cout << answer;

	return 0;
}