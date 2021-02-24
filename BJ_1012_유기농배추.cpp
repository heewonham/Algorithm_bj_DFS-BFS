#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
	int i, j, k, x, y;
	int test, row, column, n;
	int count = 0;
	cin >> test;
	queue<pair<int, int>> worm;
	vector<int> needed;
	for (i = 0; i < test; i++) {
		cin >> row >> column >> n;
		int farm[50][50] = { 0 };
		bool visited[50][50] = { false };

		// 1. 입력
		for (j = 0; j < n; j++) {
			cin >> x >> y;
			farm[x][y] = 1;
		}
		// 2. 찾기
		for (j = 0; j < row; j++) {
			for (k = 0; k < column; k++) {
				if (farm[j][k] == 1 && !visited[j][k]) {
					visited[j][k] = true;
					count++;
					worm.push(make_pair(j, k));
				}
				while (!worm.empty()) {
					x = worm.front().first;
					y = worm.front().second;
					worm.pop();
					if (x - 1 >= 0 && farm[x - 1][y] == 1 && !visited[x - 1][y]) {
						visited[x-1][y] = true;
						worm.push(make_pair(x-1, y));
					}
					if (x + 1 < row && farm[x+1][y] == 1 && !visited[x+1][y]) {
						visited[x+1][y] = true;
						worm.push(make_pair(x+1, y));
					}
					if (y - 1 >= 0 && farm[x][y-1] == 1 && !visited[x][y-1]) {
						visited[x][y-1] = true;
						worm.push(make_pair(x, y-1));
					}
					if (y+1 < column && farm[x][y+1] == 1 && !visited[x][y+1]) {
						visited[x][y+1] = true;
						worm.push(make_pair(x, y+1));
					}
			}	}
		}
		needed.push_back(count);
		count = 0;
	}
	// 3. 출력
	for (i = 0; i < needed.size(); i++)
		cout << needed[i] << endl;
}
