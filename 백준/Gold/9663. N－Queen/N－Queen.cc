#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool promising(int i, vector<int> &column)
{
	for (int j = 0; j < i; j++)
		if (column[j] == column[i] || abs(column[j] - column[i]) == i - j)
			return false;

	return true;
}

int Queens(int n, int i, vector<int>& column) {
	int cnt = 0;
	if (i == n)
		cnt++;
	else
	{
		for (int j = 0; j < n; j++)
		{
			column[i] = j;
			if (promising(i, column)) {
				cnt += Queens(n, i + 1, column);
			}
		}
	}

	return cnt;
}

int main() {
	int answer = 0;
	int n;
	cin >> n;
	vector<int> column(n);

	answer += Queens(n, 0, column);

	cout << answer;

	return 0;
}