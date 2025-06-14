#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	string S;
	cin >> S;

	vector<int> v;
	//vector<string> sv;
	int s_idx = 0;
	for (int i = 0; i < S.size(); i++)
	{
		if ((i-s_idx) % 2 == 0 && S[i] != 'I')
		{
			if (i - 2 - s_idx > 0) {
				v.push_back((i - 2 - s_idx) / 2);
				//sv.push_back(S.substr(s_idx, i - s_idx - 1));
			}
			s_idx = i + 1;
		}
		else if ((i-s_idx) % 2 == 1 && S[i] != 'O')
		{
			if (i - 1 - s_idx > 0) {
				v.push_back((i - 1 - s_idx) / 2);
				//sv.push_back(S.substr(s_idx, i - s_idx));
			}
			s_idx = i;
		}
	}

	if (S.size() - s_idx > 0)
	{
		v.push_back((S.size() - 1 - s_idx) / 2);
		//sv.push_back(S.substr(s_idx));
	}
	
	int answer = 0;
	for (int i = 0; i < v.size(); i++)
	{
		//cout << v[i] << ' ' << sv[i] << endl;
		if (N <= v[i])
			answer += v[i] - N + 1;
	}

	cout << answer;
	return 0;
}