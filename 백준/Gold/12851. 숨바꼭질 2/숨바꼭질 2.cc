#include <iostream>
#include <vector>
#include <queue>

using namespace std;

enum Operator {
	SUB,
	ADD,
	MUL
};

int Operation(int n, int op)
{
	switch (op)
	{
		case SUB:
			n--;
			break;
		case ADD:
			n++;
			break;
		case MUL:
			n *= 2;
			break;
	}

	return n;
}

pair<int, int> BFS(int N, int M)
{
	vector<int> visited(200001, 0);
	vector<int> time(200001, -1);
	queue<int> q;

	q.push(N);
	time[N] = 0;
	visited[N] = 1;

	while (!q.empty())
	{
		int size = q.size();
		for (int n = 0; n < size; n++)
		{
			int cur = q.front();
			q.pop();

			if (cur == M)
				return { time[cur], visited[cur]};

			for (int i = 0; i < 3; i++)
			{
				int next = Operation(cur, i);
				if (next>=0 && next <= 200000)
				{
					if (time[next] == -1)
					{
						time[next] = time[cur] + 1;
						visited[next] = visited[cur];
						q.push(next);
					}
					else if (time[next] == time[cur] + 1)
						visited[next] += visited[cur];
				}
			}
		}
	}

	return { time[N], visited[N] };
}

int main()
{
	int N, M;
	cin >> N >> M;

	pair<int, int> answer = BFS(N, M);
	cout << answer.first << '\n' << answer.second;

	return 0;
}