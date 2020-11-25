#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, ans;
vector<int> v;
int main() {
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++)cin >> v[i];
	sort(v.begin(), v.end());


	int le, ri;
	for (le = 0; le < v.size() - 1; le += 2) {

		if (v[le] < 1 && v[le + 1] < 1) {
			ans += (v[le] * v[le + 1]);
		}
		else {
			break;
		}
	}
	for (ri = v.size() - 1; ri >= le; ri -= 2) {
		if (v[ri] > 1 && v[ri - 1] > 1) {
			ans += (v[ri] * v[ri - 1]);
		}
		else {
			break;
		}
	}
	for (int i = le; i <= ri; i++) {
		ans += v[i];
	}
	cout << ans << '\n';
	return 0;
}
