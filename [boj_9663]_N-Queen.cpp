#include<iostream>
#include<cmath>
using namespace std;
int n, ans;
int c[20];//c[ї­]=За
bool is_possible(int rw, int cl) {
	for (int i = 0; i < cl; i++) {
		if (c[i] == c[cl]) return false;
		if (abs(c[i] - c[cl]) == abs(i - cl))return false;
	}
	return true;
}
void n_queen(int col) {
	if (col == n) {
		ans++;
		return;
	}
	for (int i = 0; i < n; i++) {
		c[col] = i;
		if (is_possible(i, col)) {
			n_queen(col + 1);
		}
		c[col] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;

	n_queen(0);
	cout << ans << '\n';
	return 0;
}