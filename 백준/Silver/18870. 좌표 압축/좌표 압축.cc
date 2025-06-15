#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;

	int num;
	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	vector<int> sorted_v(v);
	sort(sorted_v.begin(), sorted_v.end());
	sorted_v.erase(unique(sorted_v.begin(), sorted_v.end()), sorted_v.end());


	for (int i = 0; i < N; i++)
		cout << lower_bound(sorted_v.begin(), sorted_v.end(), v[i]) - sorted_v.begin() << ' ';

	return 0;
}