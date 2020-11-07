#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
const int INF = 987654321;
int dist[101][101];

int main() {
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
		dist[u - 1][v - 1] = min(dist[u - 1][v - 1], 1);
		dist[v - 1][u - 1] = min(dist[v - 1][u - 1], 1);
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	int ans = 0, val = INF;
	for (int i = 0; i < n; i++) {
		int tmp = 0;
		for (int j = 0; j < n; j++) tmp += dist[i][j];
		if (val > tmp) {
			ans = i + 1;
			val = tmp;
		}
	}
	cout << ans << '\n';
	return 0;
}