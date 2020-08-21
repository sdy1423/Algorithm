#include<iostream>
using namespace std;
int t, n;
void change(int num) {
	int cnt = 0;
	while (num) {
		if (num % 2)cout << cnt << ' ';
		num /= 2, cnt += 1;
	}
	cout << '\n';
}
int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		change(n);
	}
	return 0;
}