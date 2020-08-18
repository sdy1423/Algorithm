#include<iostream>
#include<algorithm>
using namespace std;
int n, dp[100002];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j * j <= i; j++) {
			if (j == 1) {
				dp[i] = dp[i - (j * j)] + 1;
			}
			if (dp[i] > dp[i - (j * j)] + 1) {
				dp[i] = dp[i - (j * j)] + 1;
			}
		}
	}
	cout << dp[n] << '\n';
	return 0;
}