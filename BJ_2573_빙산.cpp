#include <iostream>
#include <queue>
using namespace std;
queue <pair<pair<int, int>, int>> melt1;
queue <pair<pair<int, int>, int>> melt2;
int ice[300][300];
int visited[300][300];

int BFS(int cc, int N, int M, int X, int Y);
int pole(int x, int y, int N, int M);
int main() {
	int i, j, count = 0, year = 0;
	int N, M, x, y;

	// 1. 입력
	cin >> N >> M;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> ice[i][j];
			if (ice[i][j] > 0) { count++;	x = i; y = j; }
			visited[i][j] = 1;
	}	}

	// 2. 찾기
	year = BFS(count, N, M,x,y);

	// 3. 출력
	cout << year;
}
int BFS(int cc, int N, int M, int X, int Y) {
	int status, x, y, c;
	int count = cc;
	int year = 0, xx = X, yy = Y;
	while (count > 0) {
		// # 넣는다.
		status = 1;
		melt1.push(make_pair(make_pair(xx, yy), 0));
		melt2.push(make_pair(make_pair(xx, yy), 0));
		visited[xx][yy] *= -1;
		while (!melt1.empty()) {
			x = melt1.front().first.first;
			y = melt1.front().first.second;
			melt1.pop();
			if (x - 1 >= 0 && visited[x - 1][y] == 1 && ice[x - 1][y] != 0) {
				melt1.push(make_pair(make_pair(x - 1, y), 0));
				melt2.push(make_pair(make_pair(x - 1, y), 0));
				visited[x - 1][y] *= -1; status++;
			}
			if (x + 1 < N && visited[x + 1][y] == 1 && ice[x + 1][y] != 0) {
				melt1.push(make_pair(make_pair(x + 1, y), 0));
				melt2.push(make_pair(make_pair(x + 1, y), 0));
				visited[x + 1][y] *= -1; status++;
			}
			if (y - 1 >= 0 && visited[x][y - 1] ==1 && ice[x][y - 1] != 0) {
				melt1.push(make_pair(make_pair(x, y - 1), 0));
				melt2.push(make_pair(make_pair(x, y - 1), 0));
				visited[x][y - 1] *= -1; status++;
			}
			if (y + 1 < M && visited[x][y + 1] == 1 && ice[x][y + 1] != 0) {
				melt1.push(make_pair(make_pair(x, y + 1), 0));
				melt2.push(make_pair(make_pair(x, y + 1), 0));
				visited[x][y + 1] *= -1; status++;
			}
		}
		// #이미 나눠져있었는가?
		if (status != count) return 0;

		// # 녹는다.
		while (!melt2.empty()) {
			x = melt2.front().first.first;
			y = melt2.front().first.second;
			melt2.pop();
			melt1.push(make_pair(make_pair(x, y), pole(x, y, N, M)));
		}
		year++;
		
		// # 반영된다.
		while (!melt1.empty()) {
			x = melt1.front().first.first;
			y = melt1.front().first.second;
			c = melt1.front().second;
			melt1.pop();
			ice[x][y] = (ice[x][y] - c) < 0 ? 0 : (ice[x][y] - c);
			if (ice[x][y] == 0) count--;
			else { xx = x; yy = y; }
		}
		
		// # 이어진 덩어리인가?
		if (count > 0) { 
			melt1.push(make_pair(make_pair(xx, yy), 0));
			visited[xx][yy] *= -1; status = 1;
		}
		else status = 0; // 남은 빙하가 없다면 ,,
		while (!melt1.empty()) {
			x = melt1.front().first.first;
			y = melt1.front().first.second;
			melt1.pop();
			if (x - 1 >= 0 && visited[x - 1][y] == -1 && ice[x - 1][y] != 0) {
				melt1.push(make_pair(make_pair(x - 1, y), 0));
				visited[x - 1][y] *= -1; status++;
			}
			if (x + 1 < N && visited[x + 1][y] == -1 && ice[x + 1][y] != 0) {
				melt1.push(make_pair(make_pair(x + 1, y), 0));
				visited[x + 1][y] *= -1; status++;
			}
			if (y - 1 >= 0 && visited[x][y - 1] == -1 && ice[x][y - 1] != 0) {
				melt1.push(make_pair(make_pair(x, y - 1), 0));
				visited[x][y - 1] *= -1; status++;
			}
			if (y + 1 < M && visited[x][y + 1] == -1 && ice[x][y + 1] != 0) {
				melt1.push(make_pair(make_pair(x, y + 1), 0));
				visited[x][y + 1] *= -1; status++;
			}
		}
		if (status != count) return year;
	}
	return 0;
}
int pole(int x, int y, int N, int M) {
	int count = 0;
	if (x + 1 < N && ice[x + 1][y] == 0)
		count++;
	if (x - 1 >= 0 && ice[x - 1][y] == 0)
		count++;
	if (y + 1 < M && ice[x][y + 1] == 0)
		count++;
	if (y - 1 >= 0 && ice[x][y - 1] == 0)
		count++;
	return count;
}
