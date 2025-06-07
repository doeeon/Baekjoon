#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int people;
	int T, P;
	cin >> people;

	vector<int> t_size;
	int sum=0;
	while (1)
	{
		cin >> T;
		if (sum + T > people)
			break;
		sum += T;
		t_size.push_back(T);
	}

	cin >> P;

	int t_answer=0;
	for (int i = 0; i < t_size.size(); i++)
		t_answer += (t_size[i] + T-1) / T;

	cout << t_answer << '\n';
	cout << people / P << ' ' << people % P;

	return 0;
}