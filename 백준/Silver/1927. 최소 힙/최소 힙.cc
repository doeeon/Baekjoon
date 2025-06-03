#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> pq;
	int num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (num > 0)
			pq.push(num);
		else
		{
			if (pq.empty())
				cout << '0' << '\n';
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
	}
	return 0;
}