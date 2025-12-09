// 1715 카드 정렬하기
// 그리디
// 작은 것끼리 먼저 묶는게 훨씬 이득
// 우선순위 큐(min-heap) 이용
// 큐에 다 넣고, 2개 빼서 더하고 다시 넣고 반복
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int num;
	priority_queue<int, vector<int>, greater<>> pq;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		pq.push(num);
	}

	int answer = 0;
	while (!pq.empty())
	{
		int first = pq.top();
		pq.pop();

		if (pq.empty())
			break;

		int second = pq.top();
		pq.pop();

		answer += first + second;
		pq.push(first + second);
	}

	cout << answer;
	return 0;
}