#include<iostream>
#include<cmath>
using namespace std;
int n, tmp, ans;
void go(int idx, int arr[8]) {
	if (idx == 8) {
		int candi = 0, candi_val = 0;
		for (int i = 7; i >= 1; i--) {
			candi += (arr[i] ^ arr[i - 1]) * (int)pow(2, i);
			if (arr[i])candi_val += arr[i] * (int)pow(2, i);
		}
		candi += (arr[0] ^ 0);
		if (arr[0])candi_val += 1;
		if (candi == tmp) ans = candi_val;
		return;
	}
	arr[idx] = 0;
	go(idx + 1, arr);
	arr[idx] = 1;
	go(idx + 1, arr);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		int arr[8] = { 0, };
		go(0, arr);
		cout << ans << ' ';
	}
	cout << '\n';
	return 0;
}