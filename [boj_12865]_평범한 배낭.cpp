#include<iostream>
#include<algorithm>
using namespace std;
int n, k, w[102], v[102], dp[102][100002], ans;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (w[i] > j)dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], v[i] + dp[i - 1][j - w[i]]);
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << '\n';
	return 0;
}