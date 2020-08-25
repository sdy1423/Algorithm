#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int n, m, a, b, ans, cnt1, cnt2, cut;
vector<int> ad1[101], ad2[101];
bool visit1[101], visit2[101];
void dfs1(int node) {
	visit1[node] = true;
	for (int i = 0; i < ad1[node].size(); i++) {
		int next = ad1[node][i];
		if (!visit1[next]) {
			cnt1 += 1;
			dfs1(next);
		}
	}
}
void dfs2(int node) {
	visit2[node] = true;
	for (int i = 0; i < ad2[node].size(); i++) {
		int next = ad2[node][i];
		if (!visit2[next]) {
			cnt2 += 1;
			dfs2(next);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	cut = (n + 1) / 2;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		ad1[a].push_back(b);
		ad2[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		cnt1 = 0, cnt2 = 0;
		memset(visit1, false, sizeof(visit1));
		memset(visit2, false, sizeof(visit2));
		if (!visit1[i])dfs1(i);
		if (!visit2[i])dfs2(i);
		if (cnt1 >= cut || cnt2 >= cut)ans += 1;
	}
	cout << ans << '\n';
	return 0;
}