#include<iostream>
#include<vector>
#include<queue>
#define INF 987654321
using namespace std;
int n, m;
char tmp;
int dx[] = { -2,-2,-1,-1,1,1,2,2 };
int dy[] = { -1,1,-2,2,-2,2,-1,1 };
struct KNIGHT {
	vector<vector<int>>map;
	int k, x, y;
};
vector<KNIGHT>knight;
bool Check(int x, int y) {
	return x < 0 || y < 0 || x >= n || y >= m;
}
void Input() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	vector<vector<int>>mp(n, vector<int>(m, INF));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tmp;
			if (tmp >= '0' && tmp <= '9') {
				mp[i][j] = 0;
				knight.push_back({ mp,tmp - '0',i,j });
				mp[i][j] = INF;
			}
		}
	}
}
struct QU {
	int x, y, k, cur, val;
};
void Move(KNIGHT& knt) {
	queue<QU>qu;
	vector<vector<int>>& mp = knt.map;
	qu.push({ knt.x,knt.y,knt.k,1,1 });
	while (!qu.empty()) {
		int x = qu.front().x;
		int y = qu.front().y;
		int k = qu.front().k;
		int cur = qu.front().cur;
		int val = qu.front().val;
		qu.pop();
		for (int dir = 0; dir < 8; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (Check(nx, ny))continue;
			if (mp[nx][ny] > val) {
				mp[nx][ny] = val;
				if (cur < k)qu.push({ nx,ny,k,cur + 1,val });
				qu.push({ nx,ny,k,1,val + 1 });
			}
		}
	}
}
void Count() {
	int ans = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int sum = 0;
			bool ok = false;
			for (int h = 0; h < knight.size(); h++) {
				int temp = knight[h].map[i][j];
				if (temp == INF) {
					ok = true;
					break;
				}
				sum += temp;
			}
			if (ok)continue;
			if (ans == -1)ans = sum;
			else ans = min(ans, sum);
		}
	}
	cout << ans << '\n';
}
void Sol() {
	for (int i = 0; i < knight.size(); i++) {
		Move(knight[i]);
	}
	Count();
}
int main() {
	Input();
	Sol();
	return 0;
}