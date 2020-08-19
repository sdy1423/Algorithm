#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
char map[15][15];
bool visited[15][15], erase[15][15];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
int ans, tmp_cnt;
void dfs(int x, int y, char color) {
	visited[x][y] = true;
	erase[x][y] = true;
	tmp_cnt++;
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6)continue;
		if (!visited[nx][ny] && map[nx][ny] == color) {
			dfs(nx, ny, color);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> map[i][j];
		}
	}
	while (1) {
		bool ok = false;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (map[i][j] != '.' && !visited[i][j]) {
					tmp_cnt = 0;
					memset(erase, false, sizeof(erase));
					dfs(i, j, map[i][j]);
					if (tmp_cnt >= 4) {
						ok = true;
						for (int a = 0; a < 12; a++) {
							for (int b = 0; b < 6; b++) {
								if (erase[a][b])map[a][b] = '.';
							}
						}
					}
				}
			}
		}
		if (!ok)break;
		else ans += 1;
		for (int i = 0; i < 6; i++) {
			string str = "";
			for (int j = 11; j >= 0; j--) {
				if (map[j][i] != '.')str += map[j][i];
			}
			int n = str.size(), tmp = 0;
			for (int j = 11; j >= 0; j--) {
				if (tmp < n) {
					map[j][i] = str[tmp++];
				}
				else {
					map[j][i] = '.';
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}