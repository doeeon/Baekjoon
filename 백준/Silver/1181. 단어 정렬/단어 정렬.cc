#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(string a, string b)
{
	if (a.size() == b.size())
		return a < b;
	return a.size() < b.size();
}
int main() {
	int n;
	cin >> n;

	string str;
	vector<string> v;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		v.push_back(str);
	}
	
	sort(v.begin(), v.end(), cmp);
	v.erase(unique(v.begin(), v.end()), v.end());
	
	for (int i=0; i<v.size(); i++)
		cout << v[i] << endl;

	return 0;
}