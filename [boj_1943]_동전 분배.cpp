#include<iostream>
#include<vector>
#define MAX_V 987654321
using namespace std;
int N, Sum, Value, Cnt, Count = 3, Ans;
vector<pair<int, int>>Coin;
vector<int> dp;
void Solve() {
	dp.resize(Sum + 1);
	for (int i = 1; i <= Sum; i++)dp[i] = MAX_V;
	Ans = 0;
	if (Sum % 2 != 0)return;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= Sum; j++) {
			if (dp[j] == MAX_V)continue;
			if ((dp[j] < Coin[i].second) && (j + Coin[i].first <= Sum)) {
				if (dp[j + Coin[i].first] > dp[j] + 1) {
					dp[j + Coin[i].first] = dp[j] + 1;
				}
				dp[j] = 0;
			}
		}
	}
	if (dp[Sum / 2] != MAX_V)Ans = 1;
}
int main() {
	while (Count--) {
		cin >> N;
		Coin.resize(0);
		Sum = 0;
		for (int i = 0; i < N; i++) {
			cin >> Value >> Cnt;
			Coin.push_back({ Value,Cnt });
			Sum += Value * Cnt;
		}
		Solve();
		cout << Ans << '\n';
	}
	return 0;
}