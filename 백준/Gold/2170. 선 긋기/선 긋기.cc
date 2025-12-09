// 2170 선 긋기
// 시작점 기준 오름차순 -> 끝점 기준 오름차순 {left, right}
// 합쳐진 선의 시작점(start), 끝점(end) 기록
// 1. left >= start, right <= end 인 경우 continue
// 2. left < start 인 경우 (X)
// 3. left >= start, right > end 인 경우 end update
// 4. left > end인 경우 새로운 선 시작이므로 answer += (end-start) 하고, end, start update

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first < b.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<pair<int, int>> line(N, { 0, 0 });
	for (int i = 0; i < N; i++)
		cin >> line[i].first >> line[i].second;
	
	sort(line.begin(), line.end(), cmp);


	int answer = 0;
	int start = line[0].first;
	int end = line[0].second;
	for (int i = 1; i < N; i++)
	{
		if (line[i].first > end)
		{
			answer += (end - start);
			start = line[i].first;
			end = line[i].second;
		}
		else
		{
			if (line[i].second > end)
				end = line[i].second;
		}
	}

	answer += (end - start);
	cout << answer;
	return 0;
}
