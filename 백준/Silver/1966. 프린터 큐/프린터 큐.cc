#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int answer = 0;
		vector<int> arr(10, 0);
		queue<string> q;
		int N, goal, n;
		cin >> N >> goal;
		for (int j = 0; j < N; j++)
		{
			cin >> n;
			arr[n]++;

			if (j == goal)
				q.push(to_string(n) + "*"); // 목표 문서
			else
				q.push(to_string(n));
		}

		int priority = 9;		
		while (!q.empty())
		{
			if (arr[priority] == 0)
			{
				while (!arr[priority])
					priority--;
			}

			if (q.front()[0] == priority + '0')
			{
				answer++;
				if (q.front().back() == '*')
					break;
				arr[priority]--;
				q.pop();
			}
			else {
				q.push(q.front());
				q.pop();
			}
		}

		cout << answer << '\n';
	}

	return 0;
}