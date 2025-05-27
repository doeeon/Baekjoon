#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;
//G*100 + C*10 + F*1
//A*10000 + C*1000 + D*100 + E*10 + B
//A*10000 +	C*1010 + D*100 + G*100 + E*10 + F*1 + B*1
//모든 알파벳이 들어갈 수 있으므로 map으로 묶고 벡터로 변환하여 정렬
int main() {
	int answer = 0;
	int N;
	cin >> N;

	vector<int> v;
	map<char, int> m;
	string str;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int i = str.size() - 1; i >= 0; i--)
		{
			if (m.find(str[i]) != m.end())
				m[str[i]] += pow(10, str.size() - 1 - i);
			else
				m[str[i]] = pow(10, str.size() - 1 - i);
		}
	}

	for (auto iter = m.begin(); iter != m.end(); iter++)
		v.push_back(iter->second);

	sort(v.rbegin(), v.rend());

	for (int i = 0; i < v.size(); i++)
		answer += v[i] * (9 - i);

	cout << answer;
	return 0;
}
