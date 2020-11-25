#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int INF = 987654321;
int n, s;
int dist[11][11];
int ans = INF;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tmp;
			cin >> tmp;
			dist[i][j] = tmp;
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	vector<int> arr;
	for (int i = 0; i < n; i++)arr.push_back(i);

	do {
		if (arr[0] != s)continue;
		int tmp = 0;
		for (int i = 0; i < n - 1; i++) {
			int cur = arr[i];
			int next = arr[i + 1];
			tmp += dist[cur][next];
		}
		ans = min(ans, tmp);
	} while (next_permutation(arr.begin(), arr.end()));
	cout << ans << '\n';
	return 0;
}