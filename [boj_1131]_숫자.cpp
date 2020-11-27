#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;

const int INF = 987654321;
const int MAX_V = 10000000;

ll ans, n, a, b, k;
bool visited[MAX_V];
ll dp[MAX_V];
stack<ll> st;

ll sk(ll cur) {
	string tmp = to_string(cur);
	ll ret = 0;
	for (auto c : tmp) {
		ret += pow(c - '0', k);
	}
	return ret;
}
ll go(ll cur) {
	visited[cur] = true;
	st.push(cur);
	ll next = sk(cur);

	if (dp[next] < INF) {
		return dp[cur] = min(cur, dp[next]);
	}
	if (visited[next]) {
		//사이클 발견 
		ll min_v = INF;
		while (!st.empty()) {
			ll tp = st.top();
			min_v = min(tp, min_v);
			st.pop();
			if (tp == next)break;
		}
		while (!st.empty())st.pop();
		return dp[cur] = min_v;
	}
	return dp[cur] = min(cur, go(next));
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> a >> b >> k;
	for (int i = 0; i < MAX_V; i++) {
		dp[i] = INF;
	}

	for (int i = a; i <= b; i++) {
		ans += go(i);
		while (!st.empty())st.pop();
	}

	cout << ans << '\n';

	return 0;
}