#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;
int r, c, m, s, d, z, x, y;

int map[101][101];
int candi[101][101];

int ans;

const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,1,-1 };
const int UP = 0, DOWN = 1, RIGHT = 2, LEFT = 3;
struct SHARK {
	int row, col, speed, dir, size;
	bool alive;
};
vector<SHARK>shark;

void findShark(int idx) {
	for (int i = 0; i < r; i++) {
		if (map[i][idx]) {
			int shk = map[i][idx];
			map[i][idx] = 0;
			ans += shark[shk].size;
			shark[shk].alive = false;
			return;
		}
	}
}
int changeDir(int dir) {
	if (dir == UP)return DOWN;
	if (dir == DOWN)return UP;
	if (dir == RIGHT)return LEFT;
	if (dir == LEFT)return RIGHT;
}
void moveShark() {
	memset(candi, false, sizeof(candi));
	for (int i = 1; i < shark.size(); i++) {
		if (!shark[i].alive)continue;

		int x, y, nx, ny, cnt, dir;
		x = shark[i].row, y = shark[i].col, dir = shark[i].dir, cnt = shark[i].speed;

		if (dir == UP || dir == DOWN)cnt = cnt % ((r - 1) * 2);
		else cnt = cnt % ((c - 1) * 2);

		while (cnt--) {
			nx = x + dx[dir], ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) {
				dir = changeDir(dir);
				nx = x + dx[dir], ny = y + dy[dir];
			}
			x = nx, y = ny;
		}
		shark[i].dir = dir;

		if (candi[x][y]) {
			if (shark[candi[x][y]].size < shark[i].size) {
				shark[candi[x][y]].alive = false;
				candi[x][y] = i;
			}
			else {
				shark[i].alive = false;
			}
		}
		else {
			candi[x][y] = i;
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			map[i][j] = candi[i][j];
			if (map[i][j]) {
				shark[map[i][j]].row = i, shark[map[i][j]].col = j;
			}
		}
	}
}
void input() {
	cin >> r >> c >> m;
	shark.push_back({ -1,-1,-1,-1,-1,false });
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> s >> d >> z;
		shark.push_back({ x - 1,y - 1,s,d - 1,z,true });
	}
	for (int i = 1; i < shark.size(); i++) {
		map[shark[i].row][shark[i].col] = i;
	}
}
void print() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}
void sol() {
	if (!m)return;
	for (int i = 0; i < c; i++) {
		findShark(i);
		moveShark();
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	input();
	sol();
	cout << ans << '\n';
	return 0;
}
