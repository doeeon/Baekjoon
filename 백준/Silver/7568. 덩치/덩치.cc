#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<pair<int, int>> input;
	int a, b;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		input.push_back({ a, b });
	}

	for (int i = 0; i < input.size(); i++)
	{
		int cnt = 1;
		for (int j = 0; j < input.size(); j++)
			if (input[i].first < input[j].first && input[i].second < input[j].second)
				cnt++;

		cout << cnt << ' ';
	}

	return 0;
}