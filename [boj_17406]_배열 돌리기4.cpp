#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n, m, k, r, c, s, ans = 987654321;
int map[50][50], original[50][50];
bool visited[50][50];
vector<pair<int, pair<int, int>>> vec;
void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> original[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		cin >> r >> c >> s;
		vec.push_back({ r - 1,{c - 1,s} });
	}
}
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
void go(pair<int, int>lt, pair<int, int>lb, pair<int, int>rb, pair<int, int>rt) {
	int tmp = map[lt.first][lt.second];
	int x = lt.first, y = lt.second;
	int dir = 0;
	while (1) {
		int nx = x + dx[dir], ny = y + dy[dir];
		if (dir == 0 && lb.first == nx && lb.second == ny) {
			dir = 1;
		}
		else if (dir == 1 && rb.first == nx && rb.second == ny) {
			dir = 2;
		}
		else if (dir == 2 && rt.first == nx && rt.second == ny) {
			dir = 3;
		}
		else if (dir == 3 && lt.first == nx && lt.second == ny) {
			map[x][y] = tmp;
			break;
		}
		map[x][y] = map[nx][ny];
		x = nx, y = ny;

	}
}
int checkNum() {
	int ret = -1;
	for (int i = 0; i < n; i++) {
		int tmp = 0;
		for (int j = 0; j < m; j++) {
			tmp += map[i][j];
		}
		if (ret == -1)ret = tmp;
		else if (ret > tmp)ret = tmp;
	}
	return ret;
}
int tryOrder(vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		int r = vec[v[i]].first;
		int c = vec[v[i]].second.first;
		int s = vec[v[i]].second.second;


		pair<int, int> lt, lb, rb, rt;
		for (int j = 1; j <= s; j++) {
			lt = { r - j,c - j };
			lb = { r + j,c - j };
			rb = { r + j,c + j };
			rt = { r - j,c + j };
			go(lt, lb, rb, rt);
		}
	}
	return checkNum();
}
void sol() {
	vector<int> v;
	for (int i = 0; i < k; i++) {
		v.push_back(i);
	}
	do {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				map[i][j] = original[i][j];
			}
		}
		int tmp = tryOrder(v);
		if (tmp < ans)ans = tmp;
	} while (next_permutation(v.begin(), v.end()));
	cout << ans << '\n';
}
int main() {
	input();
	sol();
	return 0;
}