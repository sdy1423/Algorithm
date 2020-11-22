#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	vector<int> arr, ans;
	arr.resize(n, 0);
	ans.resize(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		ans[i] = arr[i];
		int tmp = 0;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && tmp < ans[j]) {
				tmp = ans[j];
			}
		}
		ans[i] += tmp;
	}
	cout << *max_element(ans.begin(), ans.end());
	return 0;
}