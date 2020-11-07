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
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dist[i][j] = i == j ? 0 : INF;

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		dist[u - 1][v - 1] = min(dist[u - 1][v - 1], w);
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

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dist[i][j] == INF)cout << 0 << ' ';
			else cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';

	return 0;
}