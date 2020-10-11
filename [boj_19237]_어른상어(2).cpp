#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int n, m, k;

const int dx[] = { 0,-1,1,0,0 };
const int dy[] = { 0,0,0,-1,1 };

const int UP = 1;
const int DOWN = 2;
const int LEFT = 3;
const int RIGHT = 4;

int DIR[401][5][5];

int sharkNum[20][20];
int kNum[20][20];
int candi[20][20];

bool range_check(int x, int y) {
	return !(x < 0 || y < 0 || x >= n || y >= n);
}
struct SHARK {
	int x, y, dir;
	bool live;
};
SHARK shark[401];


void move() {
	memset(candi, 0, sizeof(candi));
	int x, y, nx, ny, num, dir, new_dir;
	for (int i = m; i > 0; i--) {
		if (shark[i].live == false)continue;

		dir = shark[i].dir;
		x = shark[i].x, y = shark[i].y;

		bool ok1 = false;
		for (int j = 1; j < 5; j++) {
			new_dir = DIR[i][dir][j];
			nx = x + dx[new_dir];
			ny = y + dy[new_dir];
			if (!range_check(nx, ny))continue;
			if (!kNum[nx][ny]) {
				ok1 = true;
				if (candi[nx][ny]) {
					shark[candi[nx][ny]].live = false;
				}
				candi[nx][ny] = i;
				shark[i].x = nx;
				shark[i].y = ny;
				shark[i].dir = new_dir;
				break;
			}
		}
		if (ok1)continue;

		for (int j = 1; j < 5; j++) {
			new_dir = DIR[i][dir][j];
			nx = x + dx[new_dir];
			ny = y + dy[new_dir];
			if (!range_check(nx, ny))continue;
			if (sharkNum[nx][ny] == i) {
				candi[nx][ny] = i;
				shark[i].x = nx;
				shark[i].y = ny;
				shark[i].dir = new_dir;
				break;
			}
		}
	}
}

void smell() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (kNum[i][j]) {
				if (!--kNum[i][j]) { 
					sharkNum[i][j] = 0;
				}
			}
		}
	}

	for (int i = 1; i <= m; i++) { 
		if (shark[i].live == false)continue;

		int x = shark[i].x, y = shark[i].y;
		kNum[x][y] = k;
		sharkNum[x][y] = i;

	}
}
bool check_break() {
	for (int i = 2; i <= m; i++) {
		if (shark[i].live == true)return false;
	}
	return true;
}
int sol() {
	if (m == 1)return 0; 
	for (int i = 1; i <= 1000; i++) {
		move(); 
		smell(); 
		if (check_break())return i;
	}
	return -1; 
}
void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m >> k;

	int tmp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			if (tmp) {
				shark[tmp] = { i,j,-1,true };
				sharkNum[i][j] = tmp, kNum[i][j] = k;
			}
		}
	}

	for (int i = 1; i <= m; i++) {
		cin >> shark[i].dir;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j < 5; j++) {
			for (int k = 1; k < 5; k++) {
				cin >> DIR[i][j][k];
			}
		}
	}
}
int main() {
	input();
	cout << sol() << '\n';
	return 0;
}
