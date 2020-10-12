#include<iostream>
#include<algorithm>
using namespace std;
int Horse[4];
int Cube[10];
int ans;
int Score[33] = {
	0,2,4,6,8,
	10,13,16,19,25,
	30,35,40,0,12,
	14,16,18,20,22,
	24,22,24,26,28,
	30,28,27,26,32,
	34,36,38
};
int Move[33][6] = {
{0,1,2,3,4,5},
{0,2,3,4,5,14},
{0,3,4,5,14,15},
{0,4,5,14,15,16},
{0,5,14,15,16,17},
{0,6,7,8,9,10},
{0,7,8,9,10,11},
{0,8,9,10,11,12},
{0,9,10,11,12,13},
{0,10,11,12,13,13},
{0,11,12,13,13,13},
{0,12,13,13,13,13},
{0,13,13,13,13,13},
{0,13,13,13,13,13},
{0,15,16,17,18,21},
{0,16,17,18,21,22},
{0,17,18,21,22,23},
{0,18,21,22,23,24},
{0,19,20,9,10,11},
{0,20,9,10,11,12},
{0,9,10,11,12,13},
{0,22,23,24,25,29},
{0,23,24,25,29,30},
{0,24,25,29,30,31},
{0,25,29,30,31,32},
{0,26,27,28,9,10},
{0,27,28,9,10,11},
{0,28,9,10,11,12},
{0,9,10,11,12,13},
{0,30,31,32,12,13},
{0,31,32,12,13,13},
{0,32,12,13,13,13},
{0,12,13,13,13,13},
};
void go(int idx, int sum) {
	if (idx == 10) {
		ans = max(ans, sum);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int cur_idx = Horse[i];
		if (cur_idx == 13)continue;
		int cube_num = Cube[idx];
		int next_idx = Move[cur_idx][cube_num];
		if (next_idx != 13) {
			bool ok = false;
			for (int j = 0; j < 4; j++) {
				if (i == j)continue;
				if (Horse[j] == next_idx) {
					ok = true;
					break;
				}
			}
			if (ok)continue;
		}
		Horse[i] = next_idx;
		go(idx + 1, sum + Score[next_idx]);
		Horse[i] = cur_idx;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	for (int i = 0; i < 10; i++) cin >> Cube[i];
	go(0, 0);
	cout << ans << '\n';
	return 0;
}