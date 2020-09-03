#include<iostream>
using namespace std;
int n, m, k;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	while (1) {
		cin >> n >> m >> k;
		if (!n && !m && !k)break;
		bool ok = false;
		int num = n - m - k;
		for (int i = 0; i <= num; i++) {
			if (m + i > k + (num - i)) {
				cout << i << '\n';
				ok = true;
				break;
			}
		}
		if (!ok)cout << -1 << '\n';
	}
	return 0;
}