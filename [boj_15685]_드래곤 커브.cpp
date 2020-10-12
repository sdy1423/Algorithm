#include<vector>
#include<iostream>
using namespace std;
int n, x, y, d, g, ans;
bool map[210][210];
struct DRAGON {
	int x, y, dir, gen;
};
DRAGON dragon[21];
int dx[] = { 0,-1,0,1 };
int dy[] = { 1,0,-1,0 };
void input() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> y >> x >> d >> g;
		dragon[i] = { x,y,d,g };
	}
}
void moveDragon(int x, int y, int dir, int gen) {

	vector<int> vec;
	int cur_x = 100 + x, cur_y = 100 + y;
	map[cur_x][cur_y] = true;
	cur_x = cur_x + dx[dir], cur_y = cur_y + dy[dir];
	map[cur_x][cur_y] = true;
	vec.push_back(dir);


	for (int i = 1; i <= gen; i++) {
		vector<int> tmp = vec;

		for (int j = tmp.size() - 1; j >= 0; j--) {
			int tDir = (tmp[j] + 1) % 4;
			cur_x += dx[tDir], cur_y += dy[tDir];
			map[cur_x][cur_y] = true;
			vec.push_back(tDir);
		}


	}


}
void checkAns() {
	for (int i = 0; i < 208; i++) {
		for (int j = 0; j < 208; j++) {
			if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1]) {
				ans++;
			}
		}
	}
}
void sol() {
	for (int i = 0; i < n; i++) {
		moveDragon(dragon[i].x, dragon[i].y, dragon[i].dir, dragon[i].gen);
	}
	checkAns();
}
int main() {
	input();
	sol();
	cout << ans << '\n';
	return 0;
}