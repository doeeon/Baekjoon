#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Backtracking(int depth, int s, int M, vector<int>& num, vector<int>& ans)
{
	if (depth == M)
	{
		for (int i = 0; i < M; i++)
			cout << ans[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = s; i < num.size(); i++)
	{
		ans.push_back(num[i]);
		Backtracking(depth + 1, i, M, num, ans);
		ans.pop_back();
	}
}

int main()
{
	int N, M;
	cin >> N >> M;

	vector<int> num(N, 0);
	for (int i = 0; i < N; i++)
		cin >> num[i];

	sort(num.begin(), num.end());

	num.erase(unique(num.begin(), num.end()), num.end()); // 중복 원소 제거

	vector<int> ans;
	Backtracking(0, 0, M, num, ans);


	return 0;
}