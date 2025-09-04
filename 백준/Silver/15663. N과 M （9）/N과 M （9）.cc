#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Backtracking(int depth, int N, int M, vector<int>& num, vector<bool>& visited, vector<int>& answer)
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
		int last = 0;
		for (int i = 0; i < N; i++)
		{
			if (!visited[i] && num[i] != last)
			{
				answer.push_back(num[i]);
				visited[i] = true;
				last = num[i];
				Backtracking(depth + 1, N, M, num, visited, answer);
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
	vector<bool> visited(N, false);
	Backtracking(0, N, M, num, visited, answer);

	
	return 0;
}