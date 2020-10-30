#include<iostream>
using namespace std;
int n, ans;
int mp[21][21];
void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mp[i][j];
		}
	}
}
int go(int x1, int y1, int x2, int y2, bool dir) {
	int je = 0, bu = 0;
	for (int i = x1; i <= x2; i++) {
		for (int j = y1; j <= y2; j++) {
			if (mp[i][j] == 1)bu++;
			if (mp[i][j] == 2)je++;
		}
	}
	if (!bu && je == 1) {
		return 1;
	}
	int ret = 0;
	if (!dir) {
		for (int i = x1; i <= x2; i++) {
			bool star = false;
			int bu = 0;
			for (int j = y1; j <= y2; j++) {
				if (mp[i][j] == 2) {
					star = true;
					break;
				}
				if (mp[i][j] == 1)bu++;
			}
			if (!star && bu == 1) {
				ret += go(x1, y1, i - 1, y2, !dir) * go(i + 1, y1, x2, y2, !dir);
			}
		}
	}
	else {
		for (int j = y1; j <= y2; j++) {
			bool star = false;
			int bu = 0;
			for (int i = x1; i <= x2; i++) {
				if (mp[i][j] == 2) {
					star = true;
					break;
				}
				if (mp[i][j] == 1)bu++;
			}
			if (!star && bu == 1) {
				ret += go(x1, y1, x2, j - 1, !dir) * go(x1, j + 1, x2, y2, !dir);
			}
		}
	}
	return ret;
}
void sol() {
	ans = go(0, 0, n - 1, n - 1, false);
	ans += go(0, 0, n - 1, n - 1, true);
	if (!ans)cout << -1 << '\n';
	else cout << ans << '\n';
}
int main() {
	input();
	sol();
	return 0;
}