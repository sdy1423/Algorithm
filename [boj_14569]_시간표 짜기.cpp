#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
ll n, m, k, t, p, q;
vector<ll> Class, Students;
int main() {
	cin >> n;
	Class.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> t;
			Class[i] += ((ll)1 << t);
		}
	}
	cin >> m;
	Students.resize(m);
	for (int i = 0; i < m; i++) {
		cin >> p;
		for (int j = 0; j < p; j++) {
			cin >> q;
			Students[i] += ((ll)1 << q);
		}
		int ans = 0;
		for (int j = 0; j < n; j++) {
			if ((Class[j] & Students[i]) == Class[j])ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}