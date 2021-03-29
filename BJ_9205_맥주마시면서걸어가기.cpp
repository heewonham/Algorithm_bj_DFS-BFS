#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;
int main() {
	int test, n;
	int i, j;

	vector<string> answer;
	queue<pair<int, int>> BFS;
	cin >> test;

	for (i = 0; i < test; i++) {
		pair<int, int> house;
		vector<pair<int, int>> store;
		vector<bool> visited;
		bool isfind = false;
		
		// 1. �Է� 
		cin >> n;
		cin >> house.first >> house.second;
		for (j = 0; j <= n; j++) {
			int a, b;
			cin >> a >> b;
			store.push_back(make_pair(a, b));
			visited.push_back(false);
		}
		
		// 2. BFS ã�� 
		BFS.push(make_pair(house.first, house.second));
		while (!BFS.empty())
		{
			int x = BFS.front().first;
			int y = BFS.front().second;
			BFS.pop();

			if (x == store[n].first && y == store[n].second) {
				isfind = true;
				break;
			}

			for (j = 0; j <= n; j++) {
				int tmp = abs(x - store[j].first) + abs(y - store[j].second);
				if (!visited[j] && tmp <= 1000) {
					visited[j] = true;
					BFS.push(make_pair(store[j].first, store[j].second));
				}
			}
		}
		// 2-1. ã�Ҵ�? 
		if (!isfind) answer.push_back("sad");
		else answer.push_back("happy");
	}

	// 3. ���
	for (i = 0; i < answer.size(); i++)
		cout << answer[i] << endl;
}
