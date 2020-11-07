#include<iostream>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int, int> pi;
const int INF = 987654321;
int a, b, n, m;
int dist[1001];
bool visited[1001];
vector<int> arr[1001];
priority_queue<pi, vector<pi>, greater<pi>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> a >> b >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		arr[u].push_back(v);
		arr[v].push_back(u);
	}

	for (int i = 0; i <= n; i++)dist[i] = INF;
	dist[a] = 0;
	visited[a] = true;
	pq.push({ dist[a],a });

	while (!pq.empty()) {
		int curr = pq.top().second;
		pq.pop();

		for (int next : arr[curr]) {
			if (visited[next])continue;
			if (dist[next] > dist[curr] + 1) {
				dist[next] = dist[curr] + 1;
				pq.push({ dist[next],next });
			}
		}
	}

	if (dist[b] == INF)cout << -1 << '\n';
	else cout << dist[b] << '\n';

	return 0;
}