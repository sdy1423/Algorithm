#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s1, s2;
int mp[1001][1001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> s1 >> s2;
	int r = s1.size(), c = s2.size();
	for (int i = 1; i <= r; i++) {//s1
		for (int j = 1; j <= c; j++) {//s2
			if (s1[i - 1] == s2[j - 1]) mp[i][j] = mp[i - 1][j - 1] + 1;
			else mp[i][j] = max(mp[i - 1][j], mp[i][j - 1]);
		}
	}
	cout << mp[r][c] << '\n';
	string ans;
	int x = r, y = c;
	while (mp[x][y]) {
		if (s1[x - 1] == s2[y - 1]) {
			ans.push_back(s1[x - 1]);
			x--, y--;
		}
		else {
			if (mp[x - 1][y] < mp[x][y - 1]) y--;
			else x--;
		}
	}
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i];
	}
	cout << '\n';

	return 0;
}