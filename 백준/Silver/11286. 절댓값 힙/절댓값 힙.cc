#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	
	int num;
	priority_queue<int, vector<int>, greater<int>> pq;
	unordered_map<int, int> m;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		if (num != 0) //push
		{
			pq.push(abs(num));
			m[num]++;
		}
		else //pop
		{
			if (pq.empty())
				cout << 0 << '\n';
			else
			{
				int tmp = pq.top();
				if (m[-tmp] > 0)
				{
					m[-tmp]--;
					cout << -tmp << '\n';
				}
				else
				{
					m[tmp]--;
					cout << tmp << '\n';
				}
				pq.pop();
			}
		}
	}
	return 0;
}