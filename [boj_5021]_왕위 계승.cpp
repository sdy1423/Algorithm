#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
int n, m;
map<string, double> m1;
map<string, vector<string>> m2;
string king, son, parent1, parent2, want_king;
double dfs(string str) {
	double tmp = 0;
	bool ok = false;
	for (int i = 0; i < m2[str].size(); i++) {
		string next = m2[str][i];
		tmp += dfs(next);
		ok = true;
	}
	if (ok) {
		tmp /= 2;
		return tmp;
	}
	else return m1[str];
}
void init(string str) {
	map<string, double>::iterator it = m1.begin();
	for (it; it != m1.end(); it++) {
		it->second = 0;
	}
	m1[str] = 1;
}
int main() {
	cin >> n >> m >> king;
	for (int i = 0; i < n; i++) {
		cin >> son >> parent1 >> parent2;
		m2[son].push_back(parent1);
		m2[son].push_back(parent2);
	}
	m1[king] = 1;
	double max_v = -1;
	string ans;
	for (int i = 0; i < m; i++) {
		cin >> want_king;
		init(king);
		double tmp = dfs(want_king);
		if (tmp > max_v) {
			max_v = tmp;
			ans = want_king;
		}
	}
	cout << ans << '\n';
	return 0;
}