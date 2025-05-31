#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	int n;
	cin >> n;

	int x, y;
	vector<pair<int, int>> point;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		point.push_back({ x, y });
	}

	//pair 기본 정렬 기준은 first 비교, 같으면 second 비교 (오름차순)
	sort(point.begin(), point.end());

	for (int i = 0; i < n; i++)
		cout << point[i].first << ' ' << point[i].second << '\n';

	return 0;
}

