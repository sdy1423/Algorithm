#include<iostream>
#include<vector>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
vector<ll> v;
int n, m, ans = -1, song_cnt = 0;
bool visited[11];
ll sum_bit() {
	ll tmp = 0;
	for (int i = 0; i < n; i++) {
		if (visited[i]) {
			tmp |= v[i];
		}
	}
	return tmp;
}
int cur_song_cnt(ll tmp) {
	int ret = 0;
	for (int i = 0; i < m; i++) {
		if ((tmp & (1LL << i)) == (1LL << i))ret++;
	}
	return ret;
}
void go(int idx, int cur) {
	if (idx == n) {
		ll tmp = sum_bit();
		int tmp_song_cnt = cur_song_cnt(tmp);
		if (tmp_song_cnt > song_cnt) {
			song_cnt = tmp_song_cnt;
			ans = cur;
		}
		else if (tmp_song_cnt == song_cnt && ans > cur)ans = cur;
		return;
	}
	visited[idx] = false;
	go(idx + 1, cur);
	visited[idx] = true;
	go(idx + 1, cur + 1);
	visited[idx] = false;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		ll tmp = 0;
		for (int j = 0; j < m; j++) if (s2[j] == 'Y') tmp |= (1LL << j);
		v.push_back(tmp);
	}
	go(0, 0);
	cout << ans << '\n';
	return 0;
}