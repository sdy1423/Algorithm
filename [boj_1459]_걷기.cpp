#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll x, y, w, s, ans, tmp;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> x >> y >> w >> s;
	tmp = min(x, y);
	if (2 * w < s) ans = 2 * w * tmp;
	else ans = tmp * s;
	if (x > tmp || y > tmp) {
		tmp = max(x, y) - tmp;
		if (s < w) {
			if (!(tmp % 2))ans += (s * tmp);
			else {
				ans += (s * (tmp - 1));
				ans += w;
			}
		}
		else ans += (tmp * w);
	}
	cout << ans << '\n';
	return 0;
}