#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<pair<long long, long long>> points(N, { 0, 0 });
	for (int i = 0; i < N; i++)
		cin >> points[i].first >> points[i].second;

	points.push_back({ points[0].first, points[0].second });

	//Area = 1/2 abs(x_i*y_i+1 - x_i+1*y_i), (x_n+1 = x1, y_n+1 = y1)

	double answer = 0;
	for (int i = 0; i < N; i++)
		answer += (points[i].first * points[i + 1].second) - (points[i + 1].first * points[i].second);
	
	answer = abs(answer) / 2;

	cout << fixed;
	cout.precision(1);
	cout << answer;
	
	return 0;
}