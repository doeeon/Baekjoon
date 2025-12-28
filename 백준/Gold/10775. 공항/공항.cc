#include <iostream>
#include <vector>

using namespace std;

int Find(int x, vector<int>& parent)
{
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x], parent);
}

void Unite(int x, int y, vector<int>& parent)
{
	x = Find(x, parent);
	y = Find(y, parent);

	parent[x] = y;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int G, P;
	cin >> G >> P;
	
	int answer = 0;

	vector<int> parent(G + 1);
	for (int i = 0; i <= G; i++)
		parent[i] = i;

	int g;
	for (int p = 0; p < P; p++)
	{
		cin >> g;

		int gate = Find(g, parent);
		if (gate == 0)
			break;

		answer++;
		Unite(gate, gate- 1, parent);
	}

	cout << answer;
	return 0;
}