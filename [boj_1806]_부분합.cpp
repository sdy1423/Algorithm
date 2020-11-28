#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int INF = 987654321;
int n, s, ans, len = INF;
vector<int> arr;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> s;
	arr.resize(n);
	for (int i = 0; i < n; i++)cin >> arr[i];
	int lo = 0, hi = 1, tmp = arr[0];

	while (1) {
		if (tmp >= s)tmp -= arr[lo++];
		else if (hi == n)break;
		else tmp += arr[hi++];
		if (tmp >= s) len = min(len, hi - lo);
	}

	if (len == INF)cout << 0 << '\n';
	else cout << len << '\n';

	return 0;
}