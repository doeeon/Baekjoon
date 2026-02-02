#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> M >> N;

	vector<vector<int>> num(M, vector<int>(N));
	vector<set<int>> s(M); // 정렬 & 중복값 제거(중복 크기는 같은 순위로)
	vector<unordered_map<int, int>> m(M); // 각 크기별 순위 기록
	vector<vector<int>> compressed(M, vector<int>(N)); // 좌표 압축 version

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> num[i][j];
			s[i].insert(num[i][j]);
		}

		for (auto n : s[i])
			m[i][n] = m[i].size();

		for (int j = 0; j < N; j++)
			compressed[i][j] = m[i][num[i][j]];
	}

	int answer = 0;
	for (int i = 0; i < M-1; i++)
		for (int j = i + 1; j < M; j++)
		{
			bool IsEqual = true;
			for(int k=0; k<N; k++)
				if (compressed[i][k] != compressed[j][k])
				{
					IsEqual = false;
					break;
				}

			if (IsEqual)
				answer++;
		}

	cout << answer;

	return 0;
}