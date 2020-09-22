#include<iostream>
#include<string>
#include<vector>
using namespace std;
int n, r = (1 << 26) - 1, ans;
string str;
vector<int> v;
void dfs(int idx, int sum) {
	if (idx == n - 1) {
		if (sum == r)ans++;
		return;
	}
	dfs(idx + 1, sum | v[idx + 1]);
	dfs(idx + 1, sum);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	v.resize(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (char c : str) {
			v[i] |= (1 << (c - 'a'));
		}
	}
	dfs(-1, 0);
	cout << ans << '\n';
	return 0;
}