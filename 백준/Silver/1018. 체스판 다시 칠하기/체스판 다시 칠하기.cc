#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int Check(vector<string> v, int x, int y) {
	int cnt_W = 0;
	int cnt_B = 0;
	vector<string> W;
	vector<string> B;

	string tmp1 = "BWBWBWBW";
	string tmp2 = "WBWBWBWB";
	for (int i = 0; i < 8; i++)
	{
		if (i % 2 == 0)
		{
			W.push_back(tmp2);
			B.push_back(tmp1);
		}
		else
		{
			W.push_back(tmp1);
			B.push_back(tmp2);
		}
	}

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			if (v[i + x][j + y] != W[i][j])
				cnt_W++;
			if (v[i + x][j + y] != B[i][j])
				cnt_B++;
		}

	return min(cnt_W, cnt_B);
}

int main() {
	int answer = 2500;
	int N, M;
	cin >> N >> M;

	string str;
	vector<string> v;

	for (int i = 0; i < N; i++)
	{
		cin >> str;
		v.push_back(str);
	}

	for (int i = 0; i <= N - 8; i++)
		for (int j = 0; j <= M - 8; j++)
			answer = min(answer, Check(v, i, j));

	cout << answer << endl;
	return 0;
}