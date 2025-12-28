#include <iostream>
#include <vector>

using namespace std;

void Backtracking(int depth, int next, int D, int S, int& sum, vector<int>& num, int& answer)
{
	if (depth == D)
	{
		if (sum == S)	answer++;
		return;
	}

	for (int i = next; i < num.size(); i++)
	{
		sum += num[i];
		Backtracking(depth+1, i+1, D, S, sum, num, answer);
		sum -= num[i];
	}

}

int main()
{
	int N, S;
	cin >> N >> S;

	vector<int> num(N);
	for (int i = 0; i < N; i++)
		cin >> num[i];

	int answer = 0;
	int sum = 0;
	for (int i = 1; i <= N; i++)
		Backtracking(0, 0, i, S, sum, num, answer);

	cout << answer;
	return 0;
}