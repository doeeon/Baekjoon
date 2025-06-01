#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int answer = 0;
	int n;
	cin >> n;

	vector<int> time;

	int t;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		time.push_back(t);
	}

	sort(time.begin(), time.end());

	for (int i = 0; i < time.size(); i++)
		answer += time[i] * (time.size() - i);

	cout << answer << endl;

	return 0;
}