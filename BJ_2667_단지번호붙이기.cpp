#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main() {
	int n,i,j;
	int sum = 0,count = 0;
	cin >> n;
	bool visited[25][25] = {false};
	int living[25][25];
	vector<int> part;
	queue<pair<int, int>> next;

	// 1. 입력
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			scanf("%1d", &living[i][j]);
	}

	// 2. 찾기
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (living[i][j] == 1 && !visited[i][j]) {
				visited[i][j] = true;
				next.push(make_pair(i, j));
				count++;
			}
			while (!next.empty()) {
				int x = next.front().first;
				int y = next.front().second;
				next.pop();

				if (x - 1 >= 0 && living[x - 1][y] == 1 && !visited[x - 1][y]) {
					visited[x-1][y] = true;
					count++;
					next.push(make_pair(x-1, y));
				}
				if (x + 1 < 25 && living[x + 1][y] == 1 && !visited[x + 1][y]) {
					visited[x + 1][y] = true;
					count++;
					next.push(make_pair(x + 1, y));
				}
				if (y - 1 >= 0 && living[x][y-1] == 1 && !visited[x][y-1]) {
					visited[x][y-1] = true;
					count++;
					next.push(make_pair(x, y-1));
				}
				if (y + 1 < 25 && living[x][y+1] == 1 && !visited[x][y+1]) {
					visited[x][y+1] = true;
					count++;
					next.push(make_pair(x, y+1));
				}
			}
			if (count > 0) {
				sum++;
				part.push_back(count);
				count = 0;
			}
		}
	}

	// 3. 출력
	sort(part.begin(), part.end());
	cout << sum << endl;
	for (i = 0; i < sum; i++)
		cout << part[i] << endl;
}
