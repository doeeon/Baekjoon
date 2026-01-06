#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void MakeSubSum(vector<int>& A, int N, unordered_map<int, int>& m)
{
	for (int i = 0; i < N; i++)
	{
		int sum = A[i];
		m[sum]++;
		for (int j = i + 1; j < N; j++)
		{
			sum += A[j];
			m[sum]++;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T, N, M;
	cin >> T;

	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	
	cin >> M;
	vector<int> B(M);
	for (int i = 0; i < M; i++)
		cin >> B[i];

	unordered_map<int, int> SubSumA;
	unordered_map<int, int> SubSumB;

	MakeSubSum(A, N, SubSumA);
	MakeSubSum(B, M, SubSumB);

	long long answer = 0;
	for (auto iter = SubSumA.begin(); iter != SubSumA.end(); iter++)
		if (SubSumB.find(T - (iter->first)) != SubSumB.end())
			answer += (long long)iter->second * SubSumB[T - iter->first];

	cout << answer;
	return 0;
}