#include<string>
#include<vector>
#include<iostream>
using namespace std;
typedef long long ll;
int n, m, fix, ans_cnt;
bool visited[21];
ll ans;
vector<int> v1, v2;
void check_ans(ll bits) {
	for (int i = 0; i < m; i++) {
		int cnt = 0;
		for (int j = n - 1; j >= 0; j--) {
			if ((v1[i] & (1LL << j)) == (1LL << j) && (bits & (1LL << j)) == (1LL << j)) {
				cnt++;
			}
		}
		if (v2[i] != cnt)return;
	}
	ans_cnt++;
	if (ans_cnt > 1) {
		cout << "NOT UNIQUE" << '\n';
		exit(0);
	}
	ans = bits;
}
void go(int idx, ll bits) {
	if (idx == n) {
		check_ans(bits);
		return;
	}
	go(idx + 1, bits | (1LL << idx));
	go(idx + 1, bits);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	v1.resize(m, 0), v2.resize(m, 0);
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str >> v2[i];
		for (int j = 0; j < n; j++) {
			if (str[j] == '1') {
				v1[i] |= (1 << (n - 1 - j));
			}
		}
	}
	go(0, 0);
	if (!ans_cnt) {
		cout << "IMPOSSIBLE" << '\n';
	}
	else {
		for (int i = n - 1; i >= 0; i--) {
			if ((ans & (1LL << i)) == (1LL << i)) cout << 1;
			else cout << 0;
		}
		cout << '\n';
	}
	return 0;
}