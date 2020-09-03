#include<iostream>
#include<string>
using namespace std;
string muse, tmp = "abcdefghijklmnopqrstuvwxyz";
int idx_tmp, idx_muse, ans = 1;
int main() {
	cin >> muse;
	while (1) {
		char cur = muse[idx_muse];
		bool ok = false;
		for (int i = idx_tmp; i < tmp.size(); i++) {
			if (tmp[i] == cur) {
				idx_tmp = i + 1;
				idx_muse++;
				ok = true;
				break;
			}
		}
		if (!ok) {
			idx_tmp = 0;
			ans += 1;
			continue;
		}
		if (idx_muse == muse.size())break;
	}
	cout << ans << '\n';
	return 0;
}