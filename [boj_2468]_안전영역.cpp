#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n, max_v, ans;
int visited[101][101];
int map[101][101];
bool rain[101][101];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
void dfs(int x, int y, int lo) {
	visited[x][y] = lo;
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue;
		if (!rain[nx][ny] && !visited[nx][ny]) {
			dfs(nx, ny, lo);
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			max_v = max(max_v, map[i][j]);
		}
	}
	for (int r = 0; r <= max_v; r++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] <= r)rain[i][j] = true; //잠김
				else rain[i][j] = false; //잠기지 않음
			}
		}
		memset(visited, 0, sizeof(visited));
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!rain[i][j] && !visited[i][j]) {
					cnt += 1;
					dfs(i, j, cnt);
				}
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans << '\n';
	return 0;
}