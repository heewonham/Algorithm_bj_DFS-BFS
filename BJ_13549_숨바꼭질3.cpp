#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
	int n, k;
	int time = 0;
	cin >> n >> k;

	int hiddened[100001][2] = { 0 }; // 0 : �湮 1: �ð�
	queue<int> finding;

	finding.push(n);
	hiddened[n][0] = 1;
	while (!finding.empty()) {
		int x = finding.front();
		int y = hiddened[x][1]; // �ð�
		finding.pop();

		// ã�Ҵ�.
		if (k == x) {
			time = hiddened[x][1];
			break;
		}
		// 2�� �̵�
		if (x * 2 <= 100000 && hiddened[x * 2][0] == 0) {
			hiddened[x * 2][0] = 1;
			hiddened[x * 2][1] = y;
			finding.push(x * 2);
		}
		// -1 �̵�
		if (x - 1 >= 0 && hiddened[x - 1][0] == 0) {
			hiddened[x - 1][0] = 1;
			hiddened[x - 1][1] = y + 1;
			finding.push(x - 1);
		}
		// +1 �̵�
		if (x + 1 <= 100000 && hiddened[x + 1][0] == 0) {
			hiddened[x + 1][0] = 1;
			hiddened[x + 1][1] = y + 1;
			finding.push(x + 1);
		}
	}
	// �ּ� �̵� ���
	cout << time;
}
