#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void Backtracking(int depth, int start, int N, int M, vector<int>& num, vector<int>& answer)
{
	if (depth == M)
	{
		for (int i = 0; i < answer.size(); i++)
			cout << answer[i] << ' ';
		cout << '\n';
	}
	else
	{
		for (int i = start; i < N; i++)
		{
			answer.push_back(num[i]);
			Backtracking(depth + 1, i + 1, N, M, num, answer);
			answer.pop_back();
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
	Backtracking(0, 0, N, M, num, answer);

	return 0;
}