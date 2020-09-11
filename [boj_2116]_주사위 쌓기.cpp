#include<iostream>
#include<algorithm>
using namespace std;
int n, ans;
int Cube[10002][7];
int dx[7][7] = {
{0,0,0,0,0,0,0},
{0,6,4,3,2,5,1},
{0,2,6,3,1,5,4},
{0,3,2,6,4,1,5},
{0,4,1,3,6,5,2},
{0,5,2,1,4,6,3},
{0,1,2,3,4,5,6},
};
void Input() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 6; j++) {
			cin >> Cube[i][j];
		}
	}
}
void Sol() {
	int Tmp[7];
	for (int init = 1; init <= 6; init++) {
		int bottom = 0, Sum = 0;
		for (int i = 1; i <= n; i++) {
			if (i == 1) bottom = init;
			for (int j = 1; j <= 6; j++) Tmp[dx[bottom][j]] = Cube[i][j];
			int tmpMax = 0;
			for (int j = 2; j <= 5; j++) tmpMax = max(tmpMax, Tmp[j]);
			if (i < n) {
				for (int j = 1; j <= 6; j++) {
					if (Cube[i + 1][j] == Tmp[1]) {
						bottom = j;
						break;
					}
				}
			}
			Sum += tmpMax;
		}
		ans = max(ans, Sum);
	}
	cout << ans << '\n';
}
int main() {
	Input();
	Sol();
	return 0;
}