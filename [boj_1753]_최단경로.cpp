#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> pi;
const int MAX = 20001;
const int INF = 987654321;
int v, e, k;
vector<pi> arr[MAX];
bool visited[MAX];
int dist[MAX];
priority_queue<pi, vector<pi>, greater<pi>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> v >> e >> k;
	for (int i = 0; i <= v; i++)dist[i] = INF;

	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		arr[u].push_back({ v,w });//정점,거리
	}

	dist[k] = 0;
	pq.push({ dist[k],k });
	visited[k] = true;

	while (!pq.empty()) {

		int curr = pq.top().second;
		pq.pop();

		for (auto n : arr[curr]) {
			int next = n.first;
			int d = n.second;
			if (visited[next])continue;
			if (dist[next] > dist[curr] + d) {
				dist[next] = dist[curr] + d;
				pq.push({ dist[next],next });
			}
		}
	}

	for (int i = 1; i <= v; i++) {
		if (dist[i] == INF)cout << "INF\n";
		else cout << dist[i] << '\n';
	}

	return 0;
}