#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
int r, c;
char forest[50][51];

pii ddg;
vector<pii> water;

int main(){
	int i, j, min = 0;
	bool flag = false;
	
	cin >> r >> c;
	for(i= 0; i < r; i++)
		cin >> forest[i];
	
	// 두더지 찾기 
	for(i = 0; i < r; i++){
		for(j = 0; j < c; j++){
			if(forest[i][j] == 'S')
				ddg = pii(i,j);
		}
	}
	
	// 물찾기
	for(i = 0; i < r; i++){
		for(j = 0; j < c; j++){
			if(forest[i][j] == '*')
				water.push_back(pii(i,j)); 
		}
	} 
	
	// 탐색 : 이동하는 객체의 방문배열과 큐 
		// 물이동 - 두더지 이동(돌멩이 x, 끝까지 이동)
	queue<pii> water_q, ddg_q; 	// 좌표를 저장하는 큐 
		// 방문배열 필요..
	int water_vt[50][50] = {0,}, ddg_vt[50][50] = {0, };
	
		// 물 - 초기화 
	for(i = 0; i < water.size(); i++){
		pii cur_water = water[i];
		water_q.push(cur_water);
		water_vt[cur_water.first][cur_water.second] = 1;
	}
	
		// 두더지 - 초기화 
	ddg_q.push(ddg);
	ddg_vt[ddg.first][ddg.second] = 1; 
	
	// 물과 두더지가 갈 수 있는지?
	// 두더지가 비버 굴에 도착하면 거리 출력 끝.
	// 두더지가 탐색을 못하변 KAKTUS 출력하고 끝.
	while(!ddg_q.empty()){
		// 물 이동 : q에서 하나 꺼내고 상하좌우 이동 
		// 			비버 목적지 갈 수 없음, 돌멩이도 갈 수 있음.
		int water_qsz = water_q.size();
		for(i = 0; i < water_qsz; i ++){
			pii cur_water = water_q.front();
			water_q.pop();
			int x = cur_water.first;
			int y = cur_water.second;
			if(x-1 >= 0 && water_vt[x-1][y] == 0 && forest[x-1][y] != 'D' && forest[x-1][y] != 'X'){
				water_vt[x-1][y] = water_vt[x][y]+1;
				water_q.push(pii(x-1,y));
			}
			if(x+1 < r && water_vt[x+1][y] == 0 && forest[x+1][y] != 'D' && forest[x+1][y] != 'X'){
				water_vt[x+1][y] = water_vt[x][y]+1;
				water_q.push(pii(x+1,y));
			}
			if(y-1 >= 0 && water_vt[x][y-1] == 0 && forest[x][y-1] != 'D' && forest[x][y-1] != 'X'){
				water_vt[x][y-1] = water_vt[x][y]+1;
				water_q.push(pii(x,y-1));
			}
			if(y+1 < c && water_vt[x][y+1] == 0 && forest[x][y+1] != 'D' && forest[x][y+1] != 'X'){
				water_vt[x][y+1] = water_vt[x][y]+1;
				water_q.push(pii(x,y+1));
			}	
		}
		
		// 두더지 이동
		int ddg_qsz = ddg_q.size();
		for(i = 0; i< ddg_qsz; i++){
			pii cur_ddg = ddg_q.front();
			ddg_q.pop();
			int x = cur_ddg.first;
			int y = cur_ddg.second;
			if(x-1 >= 0 && water_vt[x-1][y] == 0 && ddg_vt[x-1][y] == 0 && forest[x-1][y] != 'X'){
				if (forest[x-1][y] == 'D'){
					flag = true;
					min = ddg_vt[x][y];
					break;
				}
				ddg_vt[x-1][y] = ddg_vt[x][y]+1;
				ddg_q.push(pii(x-1,y));
			}
			if(x+1 < r && water_vt[x+1][y] == 0 && ddg_vt[x+1][y] == 0 && forest[x+1][y] != 'X'){
				if (forest[x+1][y] == 'D'){
					flag = true;
					min = ddg_vt[x][y];
					break;
				}
				ddg_vt[x+1][y] = ddg_vt[x][y]+1;
				ddg_q.push(pii(x+1,y));
			}
			if(y-1 >= 0 && water_vt[x][y-1] == 0 && ddg_vt[x][y-1] == 0 && forest[x][y-1] != 'X'){
				if (forest[x][y-1] == 'D'){
					flag = true;
					min = ddg_vt[x][y];
					break;
				}
				ddg_vt[x][y-1] = ddg_vt[x][y]+1;
				ddg_q.push(pii(x,y-1));
			}
			if(y+1 < c && water_vt[x][y+1] == 0 && ddg_vt[x][y+1] == 0 && forest[x][y+1] != 'X'){
				if (forest[x][y+1] == 'D'){
					flag = true;
					min = ddg_vt[x][y];
					break;
				}
				ddg_vt[x][y+1] = ddg_vt[x][y]+1;
				ddg_q.push(pii(x,y+1));
			}		
		}
		
		if (flag)
			break;
	}
	
	// 답안 출력 
	if(flag)
		cout << min;
	else
		cout << "KAKTUS";
}
