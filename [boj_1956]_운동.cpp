#include<iostream>
#include<algorithm>
using namespace std;
int v, e;
const int INF = 987654321;
int dist[401][401];
int main() {
	ios_base::sync_with_stdio;
	cin.tie(0); cout.tie(0);

	cin >> v >> e;
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			dist[i][j] = INF;
		}
	}

	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		dist[u - 1][v - 1] = min(dist[u - 1][v - 1], w);
	}

	for (int k = 0; k < v; k++) {
		for (int i = 0; i < v; i++) {
			for (int j = 0; j < v; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	int ans = INF;
	for (int i = 0; i < v; i++) {
		ans = min(ans, dist[i][i]);
	}

	if (ans == INF)cout << -1 << '\n';
	else cout << ans << '\n';

	return 0;
}