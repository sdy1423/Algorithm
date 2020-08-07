#include<cmath>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int m, k, a, b, c;
ll n;
vector<ll> arr;
ll sum(int l, int r, int cur_l, int cur_r, int cur) {
	if (cur_l > r || cur_r < l)return 0;
	if (l <= cur_l && r >= cur_r) return arr[cur];
	int mid = (cur_l + cur_r) / 2;
	return sum(l, r, cur_l, mid, cur * 2) + sum(l, r, mid + 1, cur_r, cur * 2 + 1);
}
void change(int tgt, int var) {
	int idx = tgt + n;
	arr[idx] = var;
	while (idx > 1) {
		idx /= 2;
		arr[idx] = arr[2 * idx] + arr[2 * idx + 1];
	}
}
int main() {
	cin >> n >> m >> k;
	int tmp = n;
	for (int i = 1; i <= 63; i++) {
		if (n <= pow(2, i)) {
			n = pow(2, i);
			break;
		}
	}
	arr.resize(2 * n + 1);
	for (int i = n; i < n + tmp; i++) {
		cin >> arr[i];
	}
	for (int i = n - 1; i > 0; i--) {
		arr[i] = arr[i * 2] + arr[i * 2 + 1];
	}
	for (int i = 0; i < m + k; i++) {
		cin >> a >> b >> c;
		if (a == 1) change(b - 1, c);
		else if (a == 2) cout << sum(b, c, 1, n, 1) << '\n';
	}
	return 0;
}