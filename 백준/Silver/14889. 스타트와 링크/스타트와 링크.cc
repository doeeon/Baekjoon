// 스타트와 링크
// 조합
// N명 중 N/2명 골라서 차이값 구하기

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int Calculate(vector<int> combi, vector<vector<int>> map)
{
	vector<int> start;
	vector<int> linc;
	int s_score = 0;
	int l_score = 0;

	for (int i = 0; i < combi.size(); i++) {
		if (combi[i])
			start.push_back(i);
		else
			linc.push_back(i);
	}
	
	for (int i = 0; i < start.size()-1; i++)
		for (int j = i+1; j < start.size(); j++)
		{
			s_score += map[start[i]][start[j]] + map[start[j]][start[i]];
			l_score += map[linc[i]][linc[j]] + map[linc[j]][linc[i]];
		}
	
	return abs(s_score - l_score);
}

int main() {
	int MIN = 100 * 20 * 20;
	int N;
	cin >> N;

	vector<vector<int>> map(N, vector<int>(N, 0));
	int tmp;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> tmp;
			map[i][j] = tmp;
		}

	vector<int> combi(N, 1);
	for (int i = 0; i < N / 2; i++)
		combi[i] = 0;

	do {
		MIN = min(MIN, Calculate(combi, map));
	} while (next_permutation(combi.begin(), combi.end()));

	cout << MIN;
	return 0;
}