#include<iostream>
using namespace std;
int r, c, ans;
char mp[10001][501];
int dx[] = { -1,0,1 }, dy[] = { 1,1,1 };
bool Check(int nx, int ny) {
	if (nx >= 0 && ny >= 0 && nx < r && ny < c)return true;
	else return false;
}
bool Go(int x, int y) {
	if (y == c - 1) {
		return true;
	}
	for (int dir = 0; dir < 3; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (!Check(nx, ny))continue;
		if (mp[nx][ny] == 'x')continue;
		mp[nx][ny] = 'x';
		if (Go(nx, ny))return true;
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> mp[i][j];
	for (int i = 0; i < r; i++)
		if (Go(i, 0))ans++;
	cout << ans << '\n';
	return 0;
}