#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> pos; // 자연수
	vector<int> neg; // 음수, 0
	int n;
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		if (n > 0)
			pos.push_back(n);
		else
			neg.push_back(n);
	}

	sort(pos.rbegin(), pos.rend());
	sort(neg.begin(), neg.end());

	long long answer = 0;

	int idx = 0;
	for (idx = 0; idx < (int)neg.size() - 1; idx += 2)
	{
		if (neg[idx] == 0 || neg[idx+1] == 0) // { 0, 0 }, {음수, 0}
			break;
		answer += neg[idx] * neg[idx + 1];
	}

	if (neg.size() % 2 == 1)
		answer += neg.back();

	for (idx = 0; idx < (int)pos.size() - 1; idx += 2)
	{
		if (pos[idx] == 1 || pos[idx+1] == 1) // {1, 1}, {양수, 1}
			answer += pos[idx] + pos[idx + 1];
		else
			answer += pos[idx] * pos[idx + 1];
	}
	
	if (pos.size() % 2 == 1)
		answer += pos.back();

	
	cout << answer;
	return 0;
}