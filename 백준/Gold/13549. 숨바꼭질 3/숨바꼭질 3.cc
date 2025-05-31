#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void BFS(int n, int k, vector<int>& time) {
	vector<bool> visited(100001, false);
	deque<int> dq;

	dq.push_front(n);
	visited[n] = true;
	time[n] = 0;

	while (!dq.empty())
	{
		int x = dq.front();
		dq.pop_front();
		if (x == k)
			return;
		
		if (2 * x >= 0 && 2 * x <= 100000 && !visited[2*x])
		{
			dq.push_front(2 * x);
			time[2 * x] = time[x];
			visited[2 * x] = true;
		}
		if (x - 1 >= 0 && x - 1 <= 100000 && !visited[x - 1])
		{
			dq.push_back(x - 1);
			time[x - 1] = time[x] + 1;
			visited[x - 1] = true;
		}
		if (x + 1 >= 0 && x + 1 <= 100000 && !visited[x + 1])
		{
			dq.push_back(x + 1);
			time[x + 1] = time[x] + 1;
			visited[x + 1] = true;
		}
	}

	return;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> time(100001, -1);
	BFS(n, k, time);

	cout << time[k];
	return 0;
}