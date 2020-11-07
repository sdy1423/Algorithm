#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int INF = 987654321;
int n, m, cnt = 1;
int dist[101][101];

vector<int> arr[101];
int color[101];
bool visited[101];

void dfs(int curr, int cnt) {
	visited[curr] = true;
	color[curr] = cnt;
	for (int next : arr[curr]) {
		if (visited[next])continue;
		dfs(next, cnt);
	}
}

void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dist[i][j] = i == j ? 0 : INF;
		}
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		dist[u - 1][v - 1] = 1;
		dist[v - 1][u - 1] = 1;
		arr[u - 1].push_back(v - 1);
		arr[v - 1].push_back(u - 1);
	}
}
void cnt_color() {
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			dfs(i, cnt++);
		}
	}
}
void floyd() {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {

				if (color[i] != color[j] || color[i] != color[k] || color[j] != color[k])continue;

				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}

			}
		}
	}
}
void find_ans() {
	int color_cnt = cnt - 1;
	vector<int> ans;
	for (int k = 1; k <= color_cnt; k++) {
		int ref = 0, val = INF;
		for (int i = 0; i < n; i++) {

			if (color[i] != k)continue;
			int tmp = 0;

			for (int j = 0; j < n; j++) {
				if (dist[i][j] == INF)continue;
				tmp = max(tmp, dist[i][j]);
			}

			if (val > tmp) {
				val = tmp;
				ref = i + 1;
			}
		}
		ans.push_back(ref);
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}
}
int main() {
	input();
	cnt_color();
	floyd();
	find_ans();
	return 0;
}