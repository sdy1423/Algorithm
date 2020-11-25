#include<iostream>
#include<vector>
#include<memory.h>
using namespace std;
int n, m;
vector<int> arr[501];

bool visited[501];
bool mp[501][501];

void dfs(int start, int cur) {
	if (start != cur) {
		mp[start][cur] = true;
	}
	visited[cur] = true;
	for (int next : arr[cur]) {
		if (!visited[next]) {
			dfs(start, next);
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a - 1].push_back(b - 1);
	}
	for (int i = 0; i < n; i++) {
		memset(visited, false, sizeof(visited));
		dfs(i, i);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int tmp = 0;
		for (int j = 0; j < n; j++) {
			if (i == j)continue;
			if (mp[i][j] || mp[j][i])tmp++;
		}
		if (tmp == n - 1)ans++;

	}

	cout << ans << '\n';
	return 0;
}