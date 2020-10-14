#include<iostream>
using namespace std;
int n;
int map[2][10][4];
int ans;
void print(int color) {
	if (color == 0)cout << "green: " << '\n';
	else cout << "blue: " << '\n';

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 4; j++) {
			cout << map[color][i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}
int move_horizontal(int x, int y, int color, int num) {
	for (int i = x + 1; i < 10; i++) {
		if (map[color][i][y] || map[color][i][y + 1]) {
			if (i) {
				map[color][i - 1][y] = num;
				map[color][i - 1][y + 1] = num;
				return i - 1;
			}
		}
	}
	map[color][9][y] = num, map[color][9][y + 1] = num;
	return 9;
}
int move_vertical(int x, int y, int color, int num) {
	for (int i = x + 1; i < 10; i++) {
		if (map[color][i][y]) {
			if (i) {
				map[color][i - 1][y] = num;
				map[color][i - 2][y] = num;
			}
			return i - 1;
		}
	}
	map[color][8][y] = num, map[color][9][y] = num;
	return 9;
}
void move_one(int x, int y, int color, int num) {
	for (int j = x + 1; j < 10; j++) {
		if (map[color][j][y]) {
			if (j)map[color][j - 1][y] = num;
			return;
		}
	}
	map[color][9][y] = num;
}
void put_block(int t, int x, int y, int num) {
	if (t == 1) {
		move_one(x, y, 0, num);
		move_one(y, x, 1, num);
	}
	else if (t == 2) {
		move_horizontal(x, y, 0, num);
		move_vertical(y + 1, x, 1, num);
	}
	else if (t == 3) {
		move_vertical(x + 1, y, 0, num);
		move_horizontal(y, x, 1, num);
	}
}
int erase_full(int color) {
	for (int i = 6; i <= 9; i++) {
		bool flag = false;
		for (int j = 0; j < 4; j++) {
			if (map[color][i][j] == 0) {
				flag = true;
				break;
			}
		}
		if (!flag) { 
			ans++;
			for (int j = 0; j < 4; j++)map[color][i][j] = 0;
			return i; 
		}
	}
	return -1;
}
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
void pull_block(int idx, int color) {

	for (int row = idx - 1; row >= 0; row--) {
		for (int col = 0; col < 4; col++) {
			if (map[color][row][col]) {
				int blockIndex = map[color][row][col];
				int flag = -1;
				int n_row, n_col;
				for (int dir = 0; dir < 4; dir++) {
					n_row = row + dx[dir];
					n_col = col + dy[dir];
					if (n_row < 0 || n_col < 0 || n_row >= 10 || n_col >= 4)continue;
					if (map[color][row][col] == map[color][n_row][n_col]) {
						flag = dir;
						break;
					}
				}
				switch (flag) {
				case -1:
					map[color][row][col] = 0;
					move_one(row, col, color, blockIndex);
					break;
				case 0:
					map[color][row][col] = 0, map[color][n_row][n_col] = 0;
					move_vertical(row, col, color, blockIndex);
					break;
				case 1:
					map[color][row][col] = 0, map[color][n_row][n_col] = 0;
					move_vertical(n_row, n_col, color, blockIndex);
					break;
				case 2:
					map[color][row][col] = 0, map[color][n_row][n_col] = 0;
					move_horizontal(n_row, n_col, color, blockIndex);
					break;
				case 3:
					map[color][row][col] = 0, map[color][n_row][n_col] = 0;
					move_horizontal(row, col, color, blockIndex);
					break;
				default:
					break;
				}
			}
		}
	}

}
void check_empty(int color) {
	int idx = erase_full(color);	
	if (idx == -1)return;

	pull_block(idx, color);
	check_empty(color);
}

void move_special(int color) {
	for (int i = 9; i > 0; i--) {
		for (int j = 0; j < 4; j++) {
			map[color][i][j] = map[color][i - 1][j];
		}
	}
}
void special_chk(int color) {
	int cnt = 0;
	for (int i = 4; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if (map[color][i][j]) {
				cnt++;
				break;
			}
		}
	}
	for (int i = 0; i < cnt; i++)move_special(color);

}
void sol(int t, int x, int y, int num) {

	put_block(t, x, y, num); 
	check_empty(0);
	check_empty(1);
	special_chk(0);
	special_chk(1);
}
int count_answer() {
	int cnt = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 4; k++) {
				if (map[i][j][k])cnt++;
			}
		}
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int t, x, y;
		cin >> t >> x >> y;
		sol(t, x, y, i);
	}
	cout << ans << '\n' << count_answer() << '\n';
	return 0;
}