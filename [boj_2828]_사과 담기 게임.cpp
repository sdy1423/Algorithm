#include<iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m, j, left, right, a, ans = 0, tmp;
	cin >> n >> m >> j;
	left = 1, right = left + m - 1;
	for (int i = 0; i < j; i++) {
		cin >> a;
		if (right < a) {
			tmp = a - right;
			left += tmp, right += tmp, ans += tmp;
		}
		else if (left > a) {
			tmp = left - a;
			left -= tmp, right -= tmp, ans += tmp;
		}
	}
	cout << ans << '\n';
	return 0;
}