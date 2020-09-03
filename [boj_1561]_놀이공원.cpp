#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
ll lo, mid, hi = 60000000001, sum, minute, num, n, m;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	vector<ll> v(m);
	for (int i = 0; i < m; i++)cin >> v[i];
	if (n <= m) {
		cout << n << '\n';
	}
	else {
		while (lo + 1 < hi) {
			mid = (lo + hi) / 2;
			sum = m;
			for (int i = 0; i < v.size(); i++) {
				sum += (mid / v[i]);
			}
			if (sum < n) {
				minute = mid;
				num = n - sum;
				lo = mid;
			}
			else {
				hi = mid;
			}
		}
		minute++;
		for (int i = 0; i < v.size(); i++) {
			if (!(minute % v[i])) {
				num--;
				if (num == 0) {
					cout << i + 1 << '\n';
					break;
				}
			}
		}
	}
	return 0;
}