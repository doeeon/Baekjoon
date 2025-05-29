#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int answer = 0;

void Execution(int T, int day, vector<pair<int, int>>& schedule, int profit)
{
	// 종료 조건 day가 T이상이면
	// day가 schedule의 idx를 나타내기 때문에 day가 T인 경우에는 실제로 T+1일이다.
	if (day >= T)
	{
		answer = max(answer, profit);
		return;
	}
	
	// day + schedule.first가 T인 경우에도 가능하므로 profit을 더해줘야 하므로 수행되어야 함.
	// day + schedule.first 가 T이하면
	// 재귀(day+schedule.first)
	if (day + schedule[day].first <= T)
		Execution(T, day + schedule[day].first, schedule, profit+schedule[day].second);

	//상담 가능한 날인데도 안하고 다음 날로 pass하는 경우도 고려
	//다음 날로 재귀 (day+1)
	Execution(T, day + 1, schedule, profit);

	
}

int main() {
	int T;
	cin >> T;
	vector<pair<int, int>> schedule;
	int a, b;
	for (int i = 0; i < T; i++)
	{
		cin >> a >> b;
		schedule.push_back({ a, b });
	}

	Execution(T, 0, schedule, 0);

	cout << answer;

	return 0;
}