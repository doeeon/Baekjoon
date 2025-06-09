#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std; 

int main() {
	int N, K;
	cin >> N >> K;

	int c;
	vector<int> coins;
	for (int i = 0; i < N; i++)
	{
		cin >> c;
		coins.push_back(c);
	}

	sort(coins.begin(), coins.end(), greater<int>());
	
	int answer = K;
	for (int i = 0; i < N; i++)
	{
		int cnt = 0;
		int cost = K;
		if (coins[i] <= K) {
			for (int j = i; j < N; j++)
			{
				if (coins[j] > cost)
					continue;

				cnt += cost / coins[j];
				cost %= coins[j];

				if (cost == 0)
				{
					answer = min(answer, cnt);
					break;
				}
			}
		}
	}

	cout << answer;
	return 0;
}

// coins 벡터 내림차순 정렬
// coins[i]~coins[coins.size()-1] 까지만 사용했을 때의 동전 개수 비교