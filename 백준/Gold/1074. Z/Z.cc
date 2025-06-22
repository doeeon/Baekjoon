#include <iostream>
#include <cmath>

using namespace std;

int answer = 0;

void Divide(int r, int c, int y, int x, int N)
{
	if (N == 0) // 더 쪼갤 수 없으면 return
		return;
	// (r,c)가 몇 사분면에 있는지 확인
	if (r >= y && r < y + pow(2, N - 1) && c >= x && c < x + pow(2, N - 1))
	{
		answer += 0;
		Divide(r, c, y, x, N - 1);
	}
	else if (r >= y && r < y + pow(2, N - 1) && c >= x + pow(2, N - 1) && c < x + pow(2, N))
	{
		answer += pow(2, N - 1) * pow(2, N - 1);
		Divide(r, c, y, x + pow(2, N - 1), N - 1);
	}
	else if (r >= y+pow(2, N-1) && r < y + pow(2, N) && c >= x && c < x + pow(2, N-1))
	{
		answer += 2 * pow(2, N - 1) * pow(2, N - 1);
		Divide(r, c, y + pow(2, N - 1), x, N - 1);
	}
	else
	{
		answer += 3 * pow(2, N - 1) * pow(2, N - 1);
		Divide(r, c, y + pow(2, N - 1), x + pow(2, N - 1), N - 1);
	}
}

int main() {
	int N, r, c;
	cin >> N >> r >> c;

	Divide(r, c, 0, 0, N);

	cout << answer;

	return 0;
}