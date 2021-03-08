#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main() {
	int test, i;
	cin >> test;
	vector<int> ans;

	for (int t = 0; t < test; t++) {
		int student, temp;
		cin >> student;
		vector<int> team;
		vector<bool> isVisted;
		vector<bool> isFind;

		// 1. 입력
		for (i = 0; i < student; i++) {
			cin >> temp;
			team.push_back(temp);
			isVisted.push_back(false);
			isFind.push_back(false);
		}

		// 2. 속하지 못한 학생수 찾기
		int count = student;
		for (i = 0; i < student; i++) {
			if (count <= 0) { count = 0;  break; }
			stack<int> chk;
			int next = i;
			while (!isVisted[next]) {
				isVisted[next] = true;
				chk.push(next);
				next = team[next] - 1;
			}
			int c = 0;
			while (!chk.empty()) {
				temp = chk.top();
				if (isFind[temp]) break;
				isFind[temp] = true;
				c++;
				chk.pop();
				if (temp == next) {
					count -= c;
					break;
				}
			}
		}
		ans.push_back(count);
	}
	// 3. 출력
	for (i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
}
