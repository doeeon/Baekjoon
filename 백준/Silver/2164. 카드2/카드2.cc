#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n;
	cin >> n;

	int answer = 0;
	queue<int> q;

	for (int i = 1; i <= n; i++)
		q.push(i);

	while (q.size() > 1)
	{
		q.pop();
		q.push(q.front());
		q.pop();
	}

	cout << q.front();

	return 0;
}