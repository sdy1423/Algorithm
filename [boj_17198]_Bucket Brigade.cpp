#include<iostream>
#include<queue>
using namespace std;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
char m[11][11];
pair<int, int> Start;
int ans;
bool visited[11][11];
int idx[11][11];
bool RangeChk(int x, int y) {
	if (x < 0 || y < 0 || x >= 10 || y >= 10)return false;
	else return true;
}
void Bfs() {
	queue<pair<int, int>>q;
	q.push({ Start.first, Start.second });
	visited[Start.first][Start.second] = true;
	idx[Start.first][Start.second] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (!RangeChk(nx, ny))continue;
			if (m[nx][ny] == 'R')continue;
			if (m[nx][ny] == 'L') {
				ans = idx[x][y];
				return;
			}
			if (!visited[nx][ny]) {
				visited[nx][ny] = true;
				idx[nx][ny] = idx[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}
}
int main() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> m[i][j];
			if (m[i][j] == 'B')Start = { i,j };
		}
	}
	Bfs();
	cout << ans << '\n';
	return 0;
}