#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<pair<int, int>> fibo;
	fibo.push_back({ 1, 0 }); // fibo[0]
	fibo.push_back({ 0, 1 }); // fibo[1]

	for (int i = 2; i <= 40; i++)
		fibo.push_back({ fibo[i - 2].first + fibo[i - 1].first, fibo[i - 2].second + fibo[i - 1].second });

	int T;
	cin >> T;
	
	int n;
	for (int i = 0; i < T; i++)
	{
		cin >> n;
		cout << fibo[n].first << ' ' << fibo[n].second << '\n';
	}

	return 0;
}