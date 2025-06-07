#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int score;
	int max_score = 0;
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> score;
		max_score = max(max_score, score);
		sum += score;
	}
	
	cout << (sum / max_score * 100) / n;
	return 0;
}