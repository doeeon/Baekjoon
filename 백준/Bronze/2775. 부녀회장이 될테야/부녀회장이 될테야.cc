#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T;
	cin >> T;

	vector<vector<int>> apt(15, vector<int> (15, 0));
	for (int i = 1; i < 15; i++)
		apt[0][i] = i;

	for (int i = 1; i < 15; i++)
		for (int j = 1; j < 15; j++)
			apt[j][i] = apt[j][i - 1] + apt[j - 1][i];

	int k, n;
	for (int i = 0; i < T; i++)
	{
		cin >> k >> n;
		cout << apt[k][n] << '\n';
	}

	return 0;
}