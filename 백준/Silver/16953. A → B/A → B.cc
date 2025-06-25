#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int BFS(int A, int B)
{
	int cnt = 0;
	vector<bool> visited(B + 1, false);
	queue<int> q;

	q.push(A);
	visited[A] = true;

	while (!q.empty())
	{
		cnt++;
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			long long cur = q.front();
			if (cur == B)
				return cnt;

			if (cur * 2 <= B && !visited[cur * 2])
			{
				q.push(cur * 2);
				visited[cur * 2] = true;
			}
			if (cur*10 + 1 <= B && !visited[cur*10 + 1])
			{
				q.push(cur*10 + 1);
				visited[cur*10 + 1] = true;
			}

			q.pop();
		}
	}

	return -1;
}

int main() {
	int A, B;
	cin >> A >> B;

	cout << BFS(A, B);

	return 0;
}