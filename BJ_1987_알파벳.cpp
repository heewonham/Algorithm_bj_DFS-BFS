#include <iostream>
using namespace std;

bool alpha[26];
char matrix[20][20];
bool visited[20][20];
int max = 0;
void DFS(int x, int y, int nn, int R, int C);

int main() {
	int R, C;
	int i, j;
	string s;
	
	// 1. 입력
	cin >> R >> C;
	for (i = 0; i < R; i++) {
		cin >> s;
		for (j = 0; j < C; j++) {
			matrix[i][j] = s[j];
		}
	}

	// 2. 최대값찾기
	DFS(0, 0, 1, R, C);
	cout << ::max;
}

void DFS(int x, int y, int nn, int R, int C) {
	int num = nn;
	alpha[matrix[x][y] - 'A'] = true;
	visited[x][y] = true;
	if (::max < num) ::max = num;
	if (::max >= 26) return;
	if (x - 1 >= 0 && !alpha[matrix[x - 1][y]-'A'] && !visited[x - 1][y]) {
		DFS(x - 1, y, num + 1, R, C);
	}
	if (x + 1 < R && !alpha[matrix[x + 1][y] - 'A'] && !visited[x + 1][y]) {
		DFS(x + 1, y, num + 1, R, C);
	}
	if (y - 1 >= 0 && !alpha[matrix[x][y - 1] - 'A'] && !visited[x][y-1]) {
		DFS(x, y - 1 , num + 1, R, C);
	}
	if (y + 1 < C && !alpha[matrix[x][y + 1] - 'A'] && !visited[x][y + 1]) {
		DFS(x, y + 1, num + 1, R, C);
	}
	alpha[matrix[x][y] - 'A'] = false;
	visited[x][y] = false;
}
