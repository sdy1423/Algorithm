#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int n, x, y, ans;
vector<pair<int, int>> v1, v2;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v1.push_back({ x,y });
		v2.push_back({ y,x });
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	bool ok1 = false, ok2 = false;
	for (int i = 0; i < n - 1; i++) {
		if (v1[i].first == v1[i + 1].first) {
			if (!ok1) {
				ans++;
				ok1 = true;
			}
		}
		else ok1 = false;
		if (v2[i].first == v2[i + 1].first) {
			if (!ok2) {
				ans++;
				ok2 = true;
			}
		}
		else ok2 = false;
	}
	cout << ans << '\n';
	return 0;
}