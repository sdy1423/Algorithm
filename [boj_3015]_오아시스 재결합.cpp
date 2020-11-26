#include<iostream>
#include<stack>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
int n;
ll ans;
stack<pi> st;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		ll tmp;
		cin >> tmp;
		pi next = { tmp,1 };

		while (!st.empty()) {
			pi top = st.top();
			if (top.first <= next.first) {
				st.pop();
				ans += top.second;
				if (top.first == next.first) {
					next.second += top.second;
				}
			}
			else {
				ans++;
				break;
			}
		}
		st.push(next);
	}
	cout << ans << '\n';

	return 0;
}