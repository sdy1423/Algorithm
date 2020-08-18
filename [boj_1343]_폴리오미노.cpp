#include<iostream>
#include<string>
using namespace std;
string str, ans;
bool insert(int cnt) {
	bool ok = false;
	while (1) {
		if (cnt >= 4) ans += "AAAA", cnt -= 4;
		else if (cnt >= 2) ans += "BB", cnt -= 2;
		else if (!cnt) {
			ok = true;
			break;
		}
		else break;
	}
	if (!ok)return false;
	else return true;
}
int main() {
	cin >> str;
	bool ok = false;
	int cnt = 0;
	ans = "";
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '.') {
			if (!ok) {
				ans += '.';
				continue;
			}
			else {
				if (!insert(cnt)) {
					cout << -1 << '\n';
					return 0;
				}
				ok = false;
			}
			ans += '.';
		}
		else {
			if (!ok) {
				ok = true;
				cnt = 1;
			}
			else cnt += 1;
		}
	}
	if (ok) {
		if (!insert(cnt)) {
			cout << -1 << '\n';
			return 0;
		}
	}
	cout << ans << '\n';
	return 0;
}