#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Backtracking(int depth, int N, int M, vector<int>& num, vector<int>& answer, vector<bool>& visited)
{
	if (depth == M)
	{
		for (int i = 0; i < answer.size(); i++)
			cout << answer[i] << ' ';
		cout << '\n';
		return;
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (!visited[i])
			{
				visited[i] = true;
				answer.push_back(num[i]);
				Backtracking(depth + 1, N, M, num, answer, visited);
				answer.pop_back();
				visited[i] = false;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	
	vector<int> num(N, 0);
	int n;
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		num[i] = n;
	}
	
	sort(num.begin(), num.end());

	vector<int> answer;
	vector<bool> visited(N + 1, false);
	Backtracking(0, N, M, num, answer, visited);

	return 0;
}