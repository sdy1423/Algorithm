#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
const int max_v = 300001;
int n, k;
ll ans;
int bag[max_v];
pair<int, int>jewerly[max_v];
priority_queue<int> pq;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> jewerly[i].first >> jewerly[i].second;
	}
	for (int i = 0; i < k; i++) {
		cin >> bag[i];
	}
	sort(jewerly, jewerly + n);
	sort(bag, bag + k);
	for (int i = 0, idx = 0; i < k; i++) {
		while (idx < n && jewerly[idx].first <= bag[i]) {
			pq.push(jewerly[idx++].second);
		}
		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans << '\n';
	return 0;
}