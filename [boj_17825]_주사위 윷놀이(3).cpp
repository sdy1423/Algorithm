#include<iostream>
#include<cstring>
using namespace std;
int horse[4];
int cube[10];
int move_map[33][6] = {
{0,1,2,3,4,5},
{2,2,3,4,5,14},
{4,3,4,5,14,15},
{6,4,5,14,15,16},
{8,5,14,15,16,17},
{10,6,7,8,9,10},
{13,7,8,9,10,11},
{16,8,9,10,11,12},
{19,9,10,11,12,13},
{25,10,11,12,13,13},
{30,11,12,13,13,13},
{35,12,13,13,13,13},
{40,13,13,13,13,13},
{0,13,13,13,13,13},
{12,15,16,17,18,21},
{14,16,17,18,21,22},
{16,17,18,21,22,23},
{18,18,21,22,23,24},
{20,19,20,9,10,11},
{22,20,9,10,11,12},
{24,9,10,11,12,13},
{22,22,23,24,25,29},
{24,23,24,25,29,30},
{26,24,25,29,30,31},
{28,25,29,30,31,32},
{30,26,27,28,9,10},
{28,27,28,9,10,11},
{27,28,9,10,11,12},
{26,9,10,11,12,13},
{32,30,31,32,12,13},
{34,31,32,12,13,13},
{36,32,12,13,13,13},
{38,12,13,13,13,13},
};
bool visited[33];
int find_ans(int score) {
	int sum = 0;
	memset(visited, false, sizeof(visited));
	memset(horse, false, sizeof(horse));
	for (int i = 0; i < 10; i++) {
		int cur = (score >> (i * 2)) & 3;
		int& cur_pos = horse[cur];
		int cube_num = cube[i];
		int next_pos = move_map[cur_pos][cube_num];

		if (next_pos != 13 && visited[next_pos])return -1;

		sum += move_map[next_pos][0];
		visited[cur_pos] = false;
		visited[next_pos] = true;
		cur_pos = next_pos;

	}
	return sum;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	for (int i = 0; i < 10; i++) cin >> cube[i];

	int ans = 0;
	for (int score = 0; score < (1 << 20); score++) {
		int candi = find_ans(score);
		if (ans < candi) ans = candi;
	}

	cout << ans << '\n';
	return 0;
}
