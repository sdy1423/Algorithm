#include<iostream>
#include<cstring>
using namespace std;
char mp[27][27], ans;
int cnt[27], n, tmp, hor[27], ver[27];
void Input() {
	memset(cnt, false, sizeof(cnt));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mp[i][j];
			cnt[mp[i][j] - 'A']++;
		}
	}
}
void CheckOne() {
	for (int i = 0; i < n; i++) {
		bool ok = false;
		for (int j = 0; j < n; j++) {
			tmp = mp[i][j] - 'A';
			if (cnt[tmp] == 1) {
				cout << i + 1 << ' ' << j + 1 << ' ' << ans << '\n';
				return;
			}
		}
	}
}
bool CheckVer(int col) {
	memset(ver, 0, sizeof(ver));
	for (int i = 0; i < n; i++) {
		tmp = mp[i][col] - 'A';
		ver[tmp]++;
	}
	for (int i = 0; i < n; i++) {
		tmp = mp[i][col] - 'A';
		if (ver[tmp] > 1) return true;
	}
	return false;
}
void CheckTwo() {
	for (int i = 0; i < n; i++) {
		memset(hor, 0, sizeof(hor));
		for (int j = 0; j < n; j++) {
			hor[mp[i][j] - 'A']++;
		}
		for (int j = 0; j < n; j++) {
			tmp = mp[i][j] - 'A';
			if (hor[tmp] > 1)
				if (CheckVer(j)) {
					cout << i + 1 << ' ' << j + 1 << ' ' << ans << '\n';
					return;
				}
		}
	}
}
void Dicide() {
	bool ok = false;
	for (int i = 0; i < 27; i++) {
		if (!cnt[i])continue;
		if (cnt[i] == 1) {
			ok = true;
		}
		if (cnt[i] == n - 1) {
			ans = i + 'A';
		}
	}
	if (ok)CheckOne();
	else CheckTwo();
}
int main() {
	while (cin >> n) {
		Input();
		Dicide();
	}
	return 0;
}