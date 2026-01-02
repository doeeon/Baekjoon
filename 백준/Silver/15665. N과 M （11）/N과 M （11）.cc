#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Backtracking(int depth, int N, int M, vector<int>& num, vector<int>& answer)
{
	if (depth == M)
	{
		for (int a : answer)
			cout << a << ' ';
		cout << '\n';
		return;
	}

	int last = 0;
	for (int i = 0; i < num.size(); i++)
	{
		if (last == num[i]) continue;
		last = num[i];
		answer.push_back(num[i]);
		Backtracking(depth + 1, N, M, num, answer);
		answer.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> num(N);
	for (int i = 0; i < N; i++)
		cin >> num[i];

	sort(begin(num), end(num));

	vector<int> answer;
	Backtracking(0, N, M, num, answer);

	return 0;
}