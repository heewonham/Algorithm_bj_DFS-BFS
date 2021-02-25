#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int farm[1000][1000] = { 0 };
bool visited[1000][1000] = { false };
int main() {
	int i, j, status;
	int M, N;
	int days = 0, ripped = 0, unripped = 0;
	queue<pair<pair<int, int>,int> > tomato;

	// 1. 입력
	cin >> M >> N;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> status;
			farm[i][j] = status;
			if (status == 0)
				unripped++;
			else if (status == 1) {
				ripped++;
				tomato.push(make_pair(make_pair(i, j),0));
				visited[i][j] = true;
			}
		}
	}
	// 2. 찾기.
	if (unripped == 0) days = 0;
	else {
		while (!tomato.empty()) {
			int x = tomato.front().first.first;
			int y = tomato.front().first.second;
			int c = tomato.front().second;
			tomato.pop();

			// 최고날짜
			if (days < c) days = c;
			
			if (x - 1 >= 0 && !visited[x - 1][y] && farm[x - 1][y] == 0) {
				unripped--;
				ripped++;
				tomato.push(make_pair(make_pair(x-1, y), c+1));
				visited[x-1][y] = true;
			}
			if (x + 1 < N && !visited[x + 1][y] && farm[x + 1][y] == 0) {
				unripped--;
				ripped++;
				tomato.push(make_pair(make_pair(x + 1, y), c + 1));
				visited[x + 1][y] = true;
			}
			if (y - 1 >= 0 && !visited[x][y-1] && farm[x][y-1] == 0) {
				unripped--;
				ripped++;
				tomato.push(make_pair(make_pair(x, y-1), c + 1));
				visited[x][y-1] = true;
			}
			if (y + 1 < M && !visited[x][y+1] && farm[x][y+1] == 0) {
				unripped--;
				ripped++;
				tomato.push(make_pair(make_pair(x, y+1), c + 1));
				visited[x][y+1] = true;
			}
		}
		if (unripped > 0) days = -1;
	}
	// 3. 출력
	cout << days;
}
