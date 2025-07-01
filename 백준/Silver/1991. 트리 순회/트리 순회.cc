#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void pre_traverse(char root, unordered_map<char, pair<char, char>>& node)
{
	if (node.find(root) == node.end())
		return;

	cout << root;
	pre_traverse(node[root].first, node);
	pre_traverse(node[root].second, node);
}

void in_traverse(char root, unordered_map<char, pair<char, char>>& node)
{
	if (node.find(root) == node.end())
		return;

	in_traverse(node[root].first, node);
	cout << root;
	in_traverse(node[root].second, node);
}

void post_traverse(char root, unordered_map<char, pair<char, char>>& node)
{
	if (node.find(root) == node.end())
		return;

	post_traverse(node[root].first, node);
	post_traverse(node[root].second, node);
	cout << root;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;


	unordered_map<char, pair<char, char>> node;
	char a, b, c;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b >> c;
		node[a] = { b, c };
	}

	pre_traverse('A', node);
	cout << '\n';
	in_traverse('A', node);
	cout << '\n';
	post_traverse('A', node);
	cout << '\n';

	return 0;
}