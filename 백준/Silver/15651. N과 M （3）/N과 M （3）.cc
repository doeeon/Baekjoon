#include <iostream>
#include <vector>

using namespace std;

void Selection(int n, int m, int depth, vector<int> &answer)
{
	if (depth == m)
	{
		for (int i = 0; i < m; i++)
			cout << answer[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		answer[depth] = i;
		Selection(n, m, depth + 1, answer);
	}
}

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> answer(M);
	Selection(N, M, 0, answer);

	return 0;
}