#include<iostream>
#include<queue>
using namespace std;
int r, c;
char map[251][251];
bool visited[251][251];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int wolf_cnt, sheep_cnt;
void go(int row, int col) {
	queue<pair<int, int>> qu;
	qu.push({ row,col });
	visited[row][col] = true;
	int w = 0, s = 0;
	if (map[row][col] == 'o')s += 1;
	if (map[row][col] == 'v')w += 1;
	while (!qu.empty()) {
		int x = qu.front().first;
		int y = qu.front().second;
		qu.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c)continue;
			if (map[nx][ny] == '#')continue;
			if (!visited[nx][ny]) {
				visited[nx][ny] = true;
				qu.push({ nx,ny });
				if (map[nx][ny] == 'o')s += 1;
				if (map[nx][ny] == 'v')w += 1;
			}
		}
	}
	if (s > w)sheep_cnt += s;
	else wolf_cnt += w;
}
int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (!visited[i][j] && map[i][j] != '#') {
				go(i, j);
			}
		}
	}
	cout << sheep_cnt << ' ' << wolf_cnt << '\n';
	return 0;
}