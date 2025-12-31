#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Backtracking(int depth, int idx, int M, int N, vector<int>& num, vector<int>& answer)
{
	if (depth == M)
	{
		for (int a : answer)
			cout << a << ' ';
		cout << '\n';
	}

	int last = 0;
	for (int i = idx; i < N; i++)
	{
		if (num[i] == last)	continue;
		answer.push_back(num[i]);
		last = num[i];
		Backtracking(depth + 1, i + 1, M, N, num, answer);
		answer.pop_back();
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	
	vector<int> num(N);
	for (int i = 0; i < N; i++)
		cin >> num[i];

	sort(begin(num), end(num));

	vector<int> answer;
	Backtracking(0, 0, M, N, num, answer);

	return 0;
}