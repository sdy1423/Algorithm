#include<iostream>
#include<cstring>
using namespace std;
int n, m, k, sec, smell[21][21], kmap[21][21], tmp, nextMap[21][21], pmap[401][5][5];
struct SHARK {
	int x, y, dir;
	bool alive;
};
SHARK shark[401];
pair<pair<int, int>, int> nextLocation[401];
int dx[] = { -2, -1,1,0,0 }, dy[] = { -2 ,0,0,-1,1 };
bool CheckRange(int x, int y) {
	return !(x < 0 || y < 0 || x >= n || y >= n);
}
void Input() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			if (tmp) {
				smell[i][j] = tmp;
				kmap[i][j] = k;
				shark[tmp] = { i,j,0,true };
			}
		}
	}
	for (int i = 1; i <= m; i++) cin >> shark[i].dir;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int k = 1; k <= 4; k++) {
				cin >> pmap[i][j][k];
			}
		}
	}
}
bool CheckEnd() {
	for (int i = 2; i <= m; i++) {
		if (shark[i].alive == true)return false;
	}
	return true;
}
void FindNext() {
	for (int i = 1; i <= m; i++) {
		if (shark[i].alive == false)continue;
		int x = shark[i].x, y = shark[i].y;
		bool ok = false;
		for (int dir = 1; dir <= 4; dir++) {
			int d = pmap[i][shark[i].dir][dir];
			int nx = x + dx[d], ny = y + dy[d];
			if (!CheckRange(nx, ny))continue;
			if (!smell[nx][ny]) {
				nextLocation[i] = { {d,nx},ny };
				ok = true;
				break;
			}
		}
		if (!ok) {
			for (int dir = 1; dir <= 4; dir++) {
				int d = pmap[i][shark[i].dir][dir];
				int nx = x + dx[d], ny = y + dy[d];
				if (!CheckRange(nx, ny))continue;
				if (i == smell[nx][ny]) {
					nextLocation[i] = { {d,nx},ny };
					break;
				}
			}
		}
	}
}
void Move() {
	memset(nextMap, 0, sizeof(nextMap));
	for (int i = m; i > 0; i--) {
		if (shark[i].alive == false)continue;
		int nx = nextLocation[i].first.second, ny = nextLocation[i].second;
		if (nextMap[nx][ny]) shark[nextMap[nx][ny]].alive = false;
		nextMap[nx][ny] = i;
		shark[i].dir = nextLocation[i].first.first;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (nextMap[i][j]) {
				smell[i][j] = nextMap[i][j];
				kmap[i][j] = k;
				shark[nextMap[i][j]].x = i;
				shark[nextMap[i][j]].y = j;
			}
		}
	}
}
void TimeSub() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (kmap[i][j]) {
				kmap[i][j] -= 1;
				if (!kmap[i][j]) {
					smell[i][j] = 0;
				}
			}
		}
	}
}
void Sol() {
	while (1) {
		FindNext();
		TimeSub();
		Move();
		sec += 1;
		if (sec > 1000) {
			sec = -1;
			break;
		}
		else if (CheckEnd()) break;
	}
	cout << sec << '\n';
}
int main() {
	Input();
	Sol();
	return 0;
}