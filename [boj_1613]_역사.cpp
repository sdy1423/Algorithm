#include<iostream>
using namespace std;

int n, k, s;
const int INF = 987654321;
int dist[401][401];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dist[i][j] = INF;
		}
	}

	for (int i = 0; i < k; i++) {
		int u, v;
		cin >> u >> v;
		dist[u - 1][v - 1] = 1;
	}

	cin >> s;

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	for (int i = 0; i < s; i++) {
		int l, r;
		cin >> l >> r;
		if (dist[l - 1][r - 1] < INF) {
			cout << -1 << '\n';
		}
		else if (dist[r - 1][l - 1] < INF) {
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}

	return 0;
}