#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N;

	int n;
	unordered_map<int, int> mp;
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		mp[n]++;
	}

	cin >> M;
	int m;
	for (int i = 0; i < M; i++)
	{
		cin >> m;
		cout << mp[m] << ' ';
	}
	return 0;
}