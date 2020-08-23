#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
vector<int> ad[10001];
vector<pair<int, int>> Rank;
int n, m, a, b, ans, tmp;
bool visited[10001];
void dfs(int idx) {
	tmp += 1, visited[idx] = true;
	for (int i = 0; i < ad[idx].size(); i++)
		if (!visited[ad[idx][i]]) dfs(ad[idx][i]);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		ad[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		tmp = 0;
		memset(visited, false, sizeof(visited));
		dfs(i);
		if (tmp >= ans) {
			ans = tmp;
			Rank.push_back({ tmp,i });
		}
	}
	sort(Rank.begin(), Rank.end());
	int max_value = -1;
	vector<int> output;
	for (int i = Rank.size() - 1; i >= 0; i--) {
		if (max_value == -1) {
			max_value = Rank[i].first;
			output.push_back(Rank[i].second);
		}
		else if (max_value == Rank[i].first) output.push_back(Rank[i].second);
		else break;
	}
	sort(output.begin(), output.end());
	for (int i = 0; i < output.size(); i++) cout << output[i] << ' ';
	cout << '\n';
	return 0;
}