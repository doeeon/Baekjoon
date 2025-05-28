#include <iostream>
#include <vector>

using namespace std;

void Selection(int n, int m, int depth, vector<int> &answer, vector<bool> &visited)
{
	if (depth == m)
	{
		for (int i = 0; i < m; i++)
			cout << answer[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			answer[depth] = i+1;
			Selection(n, m, depth+1, answer, visited);
			visited[i] = false;
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> answer(M, 0);
	vector<bool> visited(N, false);
	Selection(N, M, 0, answer, visited);

	return 0;
}