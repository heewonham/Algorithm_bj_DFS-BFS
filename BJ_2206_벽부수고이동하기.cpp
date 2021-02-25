#include <iostream>
#include <queue>
using namespace std;
int maze[1000][1000];
bool visited[1000][1000][2] = {false};
int BFS(int N, int M);
int main() {
	int i, j, count = -1;
	int N, M;
	cin >> N >> M;

	// 1. 입력
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++)
			scanf("%1d", &maze[i][j]); }

	// 2. 찾기
	count = BFS(N, M);
	
	// 출력
	cout << count;
}
int BFS(int N, int M) {
	int x, y, move, punch;
	queue < pair<pair<int, int>, pair<int, int>>> exit;
	exit.push(make_pair(make_pair(0, 0), make_pair(1, 0)));
	visited[0][0][0] = true;

	while (!exit.empty()) {
		x = exit.front().first.first;
		y = exit.front().first.second;
		move = exit.front().second.first;
		punch = exit.front().second.second;
		exit.pop();

		if (x == N - 1 && y == M - 1) 	return move;

		if (x - 1 >= 0 && !visited[x - 1][y][punch] && (maze[x - 1][y] == 0 || punch == 0)) {
			int pn = punch;
			if (maze[x - 1][y] == 1 && punch == 0) { pn = punch + 1; }
			exit.push(make_pair(make_pair(x - 1, y), make_pair(move + 1, pn)));
			visited[x - 1][y][pn] = true;
		}
		if (x + 1 < N && !visited[x + 1][y][punch] && (maze[x + 1][y] == 0 || punch == 0)) {
			int pn = punch;
			if (maze[x + 1][y] == 1 && punch == 0) { pn = punch + 1; }
			exit.push(make_pair(make_pair(x + 1, y), make_pair(move + 1, pn)));
			visited[x + 1][y][pn] = true;
		}
		if (y - 1 >= 0 && !visited[x][y - 1][punch] && (maze[x][y - 1] == 0 || punch == 0)) {
			int pn = punch;
			if (maze[x][y - 1] == 1 && punch == 0) { pn = punch + 1; }
			exit.push(make_pair(make_pair(x, y - 1), make_pair(move + 1, pn)));
			visited[x][y - 1][pn] = true;
		}
		if (y + 1 < M && !visited[x][y + 1][punch] && (maze[x][y + 1] == 0 || punch == 0)) {
			int pn = punch;
			if (maze[x][y + 1] == 1 && punch == 0) {	pn = punch + 1; }
			exit.push(make_pair(make_pair(x, y + 1), make_pair(move + 1, pn)));
			visited[x][y + 1][pn] = true;
		}
	}
	return -1;
}
