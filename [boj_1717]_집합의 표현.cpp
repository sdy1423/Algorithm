#include<iostream>
using namespace std;
int p[1000002], n, m;
int find(int a) {
	if (p[a] == -1)return a;
	return p[a] = find(p[a]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)return;
	p[a] = b;
}
int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i <= n; i++)p[i] = -1;
	for (int i = 0; i < m; i++) {
		int sign, a, b;
		cin >> sign >> a >> b;
		if (!sign)merge(a, b);
		else {
			if (find(a) == find(b))cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}