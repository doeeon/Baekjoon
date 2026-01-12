#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, H;
	cin >> N >> H;

	vector<int> up(H);
	vector<int> down(H);

	int l;
	for (int i = 0; i < N; i++)
	{
		cin >> l;
		if (i % 2 == 0)	
			down[l]++;
		else			
			up[l]++;
	}

	int obs;
	int ans, ans_cnt;
	for (int i = 1; i <= H; i++)
	{
		if (i == 1)
		{
			obs = N/2;
			ans = obs;
			ans_cnt = 1;
		}
		else if (i == H)
		{
			if (ans == N / 2)
				ans_cnt++;
		}
		else
		{
			obs = obs - down[i - 1] + up[H - i + 1];
			if (obs < ans)
			{
				ans = obs;
				ans_cnt = 1;
			}
			else if (obs == ans)
				ans_cnt++;
		}
	}

	cout << ans << ' ' << ans_cnt;
	return 0;
}