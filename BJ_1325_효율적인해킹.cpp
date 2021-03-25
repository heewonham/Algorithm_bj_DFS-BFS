#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

vector<vector<int>>hacking(10001);
vector<int> answer;
int visitedCount[10001];
bool check[10001];

int DFS(int n);
int main() {
	int i, max = 0;
	int N;
	long M;

	// 1. 입력
	cin >> N >> M;
	for (i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		hacking[b].push_back(a);
	}

	// 2. 찾기
	for (i = 1; i <= N; i++) {
			int tmp = DFS(i);

			if (max < tmp) {
				max = tmp;
				answer.clear();
				answer.push_back(i);
			}
			else if (max == tmp) {
				answer.push_back(i);
			}
			memset(check, 0, N+1);
			cout << i << " : " << tmp << endl;
	}
	// 3. 출력
	std::sort(answer.begin(), answer.end());
	for (i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
}

int DFS(int n) {
	if (check[n]) return 0;
	check[n] = true;
	visitedCount[n] = 1;
	for (int u : hacking[n]) {
		visitedCount[n] += DFS(u);
	}
	return visitedCount[n];
}
