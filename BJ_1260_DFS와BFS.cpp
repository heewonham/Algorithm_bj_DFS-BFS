#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

bool visited1[1001];
bool visited2[1001];
vector<int> vertex[1001];

void DFS(int s);
void BFS(int s);
int main() {
	int i,s,f;
	int N, M,V;
	cin >> N >> M >> V;

	for (i = 0; i < M; i++) {
		cin >> s >> f;
		vertex[s].push_back(f);
		vertex[f].push_back(s);
	}

	for (i = 1; i < N; i++) {
		sort(vertex[i].begin(), vertex[i].end()); // �������� ����
	}

	// 1. DFS(����Ž��)
	DFS(V);

	cout << endl;
	// 2. BFS(�ʺ�Ž��) - queue
	BFS(V);
}
void DFS(int s) {

	cout << s << " ";
	visited1[s] = true;

	for (int i = 0; i < vertex[s].size(); i++) {
		int x = vertex[s][i];
		if (!visited1[x]) DFS(x);
	}
}
void BFS(int s){
	queue<int> que;
	que.push(s);
	visited2[s] = true;

	while (!que.empty()) {
		int x = que.front();
		que.pop();
		cout << x << " ";

		for (int i = 0; i < vertex[x].size(); i++) {
			int y = vertex[x][i];
			if (!visited2[y]) {
				que.push(y);
				visited2[y] = true;
			}
		}
	}
}
