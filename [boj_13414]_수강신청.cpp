#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;
int k, l;
map<string, int> m;
string str;
vector<pair<string, bool>> v;
int main() {
	cin >> k >> l;
	for (int i = 0; i < l; i++) {
		cin >> str;
		if (m.find(str) == m.end()) {
			m[str] = i;
			v.push_back({ str, false });
		}
		else {
			v[m[str]].second = true;
			m[str] = i;
			v.push_back({ str,false });
		}
	}
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		if (cnt == k)break;
		if (v[i].second == false) {
			cout << v[i].first << '\n';
			cnt += 1;
		}
	}
	return 0;
}