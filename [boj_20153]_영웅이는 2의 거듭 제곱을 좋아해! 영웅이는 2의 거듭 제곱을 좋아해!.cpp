#include<iostream>
#include<algorithm>
using namespace std;
const int max_v = 2'222'225;

int n, x, ans;
int arr[max_v];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		x ^= arr[i];
	}
	ans = x;

	for (int i = 0; i < n; i++) {
		ans = max(ans, x ^ arr[i]);
	}
	cout << ans << ans << '\n';
	return 0;
}