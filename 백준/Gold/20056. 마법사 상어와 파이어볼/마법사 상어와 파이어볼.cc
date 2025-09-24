#include <iostream>
#include <vector>

using namespace std;

class Fireball {
public:
	int x;
	int y;
	int m;
	int s;
	int d;

	Fireball(int x, int y, int m, int s, int d) {
		this->x = x;
		this->y = y;
		this->m = m;
		this->s = s;
		this->d = d;
	}
};

void Move(vector<vector<vector<Fireball>>>& map, int N, Fireball f)
{
	switch (f.d) {
	case 0:
		f.y -= (f.s % N);
		if (f.y < 0) f.y += N;
		break;
	case 1:
		f.x += (f.s % N);
		f.y -= (f.s % N);
		if (f.y < 0) f.y += N;
		if (f.x >= N) f.x -= N;
		break;
	case 2:
		f.x += (f.s % N);
		if (f.x >= N) f.x -= N;
		break;
	case 3:
		f.x += (f.s % N);
		f.y += (f.s % N);
		if (f.y >= N) f.y -= N;
		if (f.x >= N) f.x -= N;
		break;
	case 4:
		f.y += (f.s % N);
		if (f.y >= N) f.y -= N;
		break;
	case 5:
		f.x -= (f.s % N);
		f.y += (f.s % N);
		if (f.y >= N) f.y -= N;
		if (f.x < 0) f.x += N;
		break;
	case 6:
		f.x -= (f.s % N);
		if (f.x < 0) f.x += N;
		break;
	case 7:
		f.x -= (f.s % N);
		f.y -= (f.s % N);
		if (f.y < 0) f.y += N;
		if (f.x < 0) f.x += N;
		break;
	default:
		break;
	}

	map[f.y][f.x].push_back(f);
}

void MoveFireball(vector<vector<vector<Fireball>>>& map, int N)
{
	vector<vector<vector<Fireball>>> n_map(N, vector<vector<Fireball>>(N, vector<Fireball>()));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
				for (int k = 0; k < map[i][j].size(); k++)
					Move(n_map, N, map[i][j][k]);

	map = n_map;
}

bool JudgeDirection(vector<Fireball> fireballs)
{
	int cnt_even = 0;
	int cnt_odd = 0;
	for (int i = 0; i < fireballs.size(); i++)
	{
		if (fireballs[i].d % 2 == 0)
			cnt_even++;
		else
			cnt_odd++;
	}

	if (cnt_even == fireballs.size() || cnt_odd == fireballs.size())
		return true; // 0 2 4 6
	else
		return false; // 1 3 5 7
}

void CombineAndDivision(vector<vector<vector<Fireball>>>& map, int N)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (map[i][j].size() > 1)
			{
				int sum_m = 0;
				int sum_s = 0;
				bool sum_d = JudgeDirection(map[i][j]);

				for (int k = 0; k < map[i][j].size(); k++)
				{
					sum_m += map[i][j][k].m;
					sum_s += map[i][j][k].s;
				}

				sum_m /= 5;
				sum_s /= map[i][j].size();
				map[i][j].clear();
				if (sum_m > 0)
					for (int t = 0; t < 4; t++)
					{
						if (sum_d)
							map[i][j].push_back(Fireball(j, i, sum_m, sum_s, 2 * t));
						else
							map[i][j].push_back(Fireball(j, i, sum_m, sum_s, 2 * t + 1));
					}
			}
}

void PrintResult(vector<vector<vector<Fireball>>>& map, int N)
{
	int result = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < map[i][j].size(); k++)
				result += map[i][j][k].m;

	cout << result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, K;
	cin >> N >> M >> K;

	vector<vector<vector<Fireball>>> map(N, vector<vector<Fireball>>(N, vector<Fireball>()));

	vector<Fireball> fireballs;
	int x, y, m, s, d;
	for (int i = 0; i < M; i++)
	{
		cin >> y >> x >> m >> s >> d;
		Fireball f(x-1, y-1, m, s, d);
		map[y-1][x-1].push_back(f);
	}
	
	for (int t = 0; t < K; t++)
	{
		MoveFireball(map, N);
		CombineAndDivision(map, N);
	}

	PrintResult(map, N);
	return 0;
}