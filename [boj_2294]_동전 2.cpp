#include<iostream>
#include<algorithm>
using namespace std;
int num[110], dp[10010], n, k;
int INF = 987654321;
int main() {
	cin >> n >> k;
	for (int i = 1; i <= k; i++) dp[i] = INF;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		for (int j = num[i]; j <= k; j++) dp[j] = min(dp[j], dp[j - num[i]] + 1);
	}
	if (dp[k] == INF)cout << -1 << '\n';
	else cout << dp[k] << '\n';
	return 0;
}
