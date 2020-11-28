#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
ll k, n, ans;
ll num[10004];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> num[i];
	}

	ll lo = 0, hi = pow(2, 31), mid;

	while (lo <= hi) {
		mid = (lo + hi) / 2;
		ll tmp = 0;
		for (int i = 0; i < k; i++) {
			tmp += (num[i] / mid);
		}
		if (tmp >= n) {
			ans = mid;
			lo = mid + 1;
		}
		else hi = mid - 1;
	}
	cout << ans << '\n';
	return 0;
}