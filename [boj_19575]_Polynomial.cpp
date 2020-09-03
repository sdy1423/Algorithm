#include<iostream>
using namespace std;
typedef long long ll;
ll n, x, a, b, ans;
const ll MOD = 1000000007;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> x;
	for (int i = n; i >= 0; i--) {
		cin >> a >> b;
		ans += a;
		if (b)ans *= x;
		ans %= MOD;
	}
	cout << ans << '\n';
	return 0;
}