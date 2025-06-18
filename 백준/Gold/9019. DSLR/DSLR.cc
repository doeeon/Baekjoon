#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int L_Shift(int A)
{
	int d[4];
	for (int i = 0; i < 4; i++)
	{
		d[3 - i] = A % 10;
		A /= 10;
	}

	return ((d[1] * 10 + d[2]) * 10 + d[3]) * 10 + d[0];
}

int R_Shift(int A)
{
	int d[4];
	for (int i = 0; i < 4; i++)
	{
		d[3 - i] = A % 10;
		A /= 10;
	}

	return ((d[3] * 10 + d[0]) * 10 + d[1]) * 10 + d[2];
}

string BFS(int A, int B) {
	queue<pair<int, string>> q;
	vector<bool> visited(20000, false);

	q.push({ A, "" });

	while (!q.empty())
	{
		if (q.front().first == B)
			return q.front().second;

		int num = q.front().first;
		string str = q.front().second;
		q.pop();

		//DSLR
		int tmp;
		tmp = (2 * num) % 10000;
		if (!visited[tmp])
		{
			visited[tmp] = true;
			q.push({ tmp, str + "D" });
		}

		tmp = (num == 0) ? 9999 : num - 1;
		if (!visited[tmp])
		{
			visited[tmp] = true;
			q.push({ tmp, str + "S" });
		}

		tmp = L_Shift(num);
		if (!visited[tmp])
		{
			visited[tmp] = true;
			q.push({ tmp, str + "L" });
		}

		tmp = R_Shift(num);
		if (!visited[tmp])
		{
			visited[tmp] = true;
			q.push({ tmp, str + "R" });
		}
	}

	
}

int main() {
	int T;
	cin >> T;


	for (int t = 0; t < T; t++)
	{
		int A, B;
		cin >> A >> B;
		cout << BFS(A, B) << '\n';
	}

	return 0;
}