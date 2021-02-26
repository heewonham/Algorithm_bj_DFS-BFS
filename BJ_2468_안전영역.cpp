# include <iostream>
# include <vector>
# include <queue>
using namespace std;
int after[100][100];
bool visited[100][100];
void reset(int N) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			visited[i][j] = false;
}
int BFS(int N, int rain) {
	int i, j, count = 0;
	queue <pair <int, int>> earth;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (after[i][j] > rain && !visited[i][j]) {
				earth.push(make_pair(i, j));
				visited[i][j] = true;
				while (!earth.empty()) {
					int x = earth.front().first;
					int y = earth.front().second;
					earth.pop();

					if (x - 1 >= 0 && !visited[x - 1][y] && after[x - 1][y] > rain) {
						earth.push(make_pair(x - 1, y)); visited[x - 1][y] = true;	           }
					if (x + 1 < N && !visited[x + 1][y] && after[x + 1][y] > rain) {
						earth.push(make_pair(x + 1, y)); visited[x + 1][y] = true;			}
					if (y - 1 >= 0 && !visited[x][y - 1]  && after[x][y - 1] > rain) {
						earth.push(make_pair(x, y - 1)); visited[x][y - 1] = true; 			}
					if (y + 1 < N && !visited[x][y + 1] && after[x][y + 1] > rain) {
						earth.push(make_pair(x, y + 1)); visited[x][y + 1] = true; 		}
				}
				count++;
			}
		}
	}
	return count;
}

int main() {
	int i, j, k;
	int N, max = 0;
	int count = 0;
	
	// 1. 입력
	cin >> N;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> after[i][j];
			if (max < after[i][j]) max = after[i][j];
		}
	}

	// 2. 최대 안전지역 구하기
	for (k = 0; k <= max; k++) {
		int temp = BFS(N, k);
		if (temp > count) count = temp;
		reset(N);
	}

	// 3. 출력
	cout << count;
}
