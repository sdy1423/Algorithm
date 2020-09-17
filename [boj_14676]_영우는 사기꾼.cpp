#include<iostream>
#include<vector>
using namespace std;
int n, m, k, a, b;
vector<int> V[100001];
int Need[100001], Cnt[100001], MyCnt[100001];
vector<pair<int, int>> info;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		V[a].push_back(b);
		Need[b]++;
	}
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		info.push_back({ a,b });
	}
	for (int i = 0; i < k; i++) {
		a = info[i].first, b = info[i].second;
		if (a == 1) {
			if (Need[b] <= Cnt[b]) {
				MyCnt[b]++;
				for (int i = 0; i < V[b].size(); i++) {
					Cnt[V[b][i]] += 1;
				}
			}
			else {
				cout << "Lier!" << '\n';
				return 0;
			}
		}
		else {
			if (MyCnt[b] > 0)MyCnt[b]--;
			else {
				cout << "Lier!" << '\n';
				return 0;
			}
		}
	}
	cout << "King-God-Emperor" << '\n';
	return 0;
}