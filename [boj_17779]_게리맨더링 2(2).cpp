#include<algorithm>
#include<vector>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int n;
int ans = -1;
int map[21][21];
int tmp[21][21];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool range_check(int x, int y) {
	return !(x < 1 || y < 1 || x > n || y > n);
}

void print() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << tmp[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void fill_color(int r, int c, int color) {
	queue<pair<int, int>> qu;
	qu.push({ r,c });
	tmp[r][c] = color;
	while (!qu.empty()) {
		int x = qu.front().first;
		int y = qu.front().second;
		qu.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (!range_check(nx, ny))continue;
			if (!tmp[nx][ny]) {
				tmp[nx][ny] = color;
				qu.push(make_pair(nx, ny));
			}
		}
	}
}

void make_region(int x, int y, int d1, int d2) {
	memset(tmp, 0, sizeof(tmp));

	for (int i = 0; i <= d1; i++) tmp[x + i][y - i] = 5;
	for (int i = 0; i <= d2; i++) tmp[x + d1 + i][y - d1 + i] = 5;
	for (int i = 0; i <= d2; i++) tmp[x + i][y + i] = 5;
	for (int i = 0; i < d1; i++) tmp[x + d2 + i][y + d2 - i] = 5;

	for (int i = y - d1 - 1; i > 0; i--) tmp[x + d1][i] = 3;
	for (int i = x + d1 + d2 + 1; i <= n; i++) tmp[i][y + d2 - d1] = 4;
	for (int i = y + d2 + 1; i <= n; i++)tmp[x + d2][i] = 2;
	for (int i = x - 1; i > 0; i--)tmp[i][y] = 1;

	fill_color(1, 1, 1);
	fill_color(1, n, 2);
	fill_color(n, 1, 3);
	fill_color(n, n, 4);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (!tmp[i][j])tmp[i][j] = 5;
}
int cal_diff() {
	int Min = 987654321, Max = 0;
	for (int i = 1; i <= 5; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (tmp[j][k] == i)cnt += map[j][k];
			}
		}
		Min = min(Min, cnt);
		Max = max(Max, cnt);
	}
	return Max - Min;
}
void sol() {
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			for (int d1 = 1; d1 <= n; d1++) {
				for (int d2 = 1; d2 <= n; d2++) {
					if (x + d1 + d2 <= n && 1 + d1 <= y && y + d2 <= n) {
						make_region(x, y, d1, d2);
						int tmp = cal_diff();
						if (ans == -1)ans = tmp;
						else ans = min(ans, tmp);
					}
				}
			}
		}
	}
}
void input() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
}
int main() {
	input();
	sol();
	cout << ans << '\n';
	return 0;
}