#include<iostream>
#include<algorithm>
using namespace std;
int n, k, lo, hi, mid, ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	lo = 1, hi = k;

	while (lo <= hi) {
		mid = (lo + hi) / 2;
		int cnt = 0;
		for (int i = 1; i <= n; i++) cnt += min(n, mid / i);
		if (cnt < k)lo = mid + 1;
		else ans = mid, hi = mid - 1;
	}

	cout << ans << '\n';
	return 0;
}