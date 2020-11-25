#include<iostream>
#include<vector>
#include<memory.h>
using namespace std;
int t, n, m;
int p[1001];

int find(int curr) {
	if (p[curr] == curr)return curr;
	return p[curr] = find(p[curr]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)return;
	p[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {

		cin >> n >> m;

		for (int i = 1; i <= n; i++)p[i] = i;
		bool ok = false;

		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			if (find(a) == find(b))ok = true;
			merge(a, b);
		}

		if (ok || m != n - 1) {
			cout << "graph\n";
			continue;
		}

		//1. 연결되어 있다.
		int tmp = find(1);
		for (int i = 2; i <= n; i++) {
			if (find(i) != tmp) {
				ok = true;
				break;
			}
		}
		if (ok) {
			cout << "graph\n";
			continue;
		}

		cout << "tree\n";

	}


	return 0;
}