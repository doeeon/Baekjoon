#include <iostream>
#include <vector>

using namespace std;

void Selection(int n, int m, int depth, int start, vector<int>& answer)
{
	if (depth == m)
	{
		for (int i = 0; i < m; i++)
			cout << answer[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = start; i <= n; i++)
	{
		answer[depth] = i;
		Selection(n, m, depth + 1, i, answer);
	}
}

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> answer(M);
	vector<bool> visited(M, false);

	Selection(N, M, 0, 1, answer);

	return 0;
}