#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	
	int tmp;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> tmp;
		if (binary_search(v.begin(), v.end(), tmp))
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}

	return 0;
}

