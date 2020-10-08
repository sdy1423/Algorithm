 #include<vector>
#include<cstring>
#include<queue>
#include<iostream>
using namespace std;
int n, m, oil;
int mp[21][21], dis[21][21], visited[21][21];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
pair<int, int> taxi;
struct CUSTOMER {
	int x1, y1, x2, y2;
};
vector<CUSTOMER> cus;
void input() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> oil;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mp[i][j];
		}
	}
	cin >> taxi.first >> taxi.second;
	taxi.first--, taxi.second--;
	cus.resize(m);
	for (int i = 0; i < m; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--, b--, c--, d--;
		cus[i].x1 = a, cus[i].y1 = b, cus[i].x2 = c, cus[i].y2 = d;
	}
}

void bfs(int r, int c) {
	memset(visited, 0, sizeof(visited));
	memset(dis, 0, sizeof(dis));
	queue<pair<int, int>> q;
	q.push(make_pair(r, c));
	visited[r][c] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue;
			if (!visited[nx][ny] && !mp[nx][ny]) {
				visited[nx][ny] = true;
				dis[nx][ny] = dis[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
}
void End() {
	cout << -1 << '\n';
	exit(0);
}
int findMinDist() {
	int cusDis = 987654321;
	int x = 0, y = 0;
	int cusMinIdx = 0, cusMinX = 0, cusMinY = 0;
	for (int i = 0; i < cus.size(); i++) {
		x = cus[i].x1, y = cus[i].y1;
		if (!visited[x][y])End();

		if (dis[x][y] < cusDis) {
			cusDis = dis[x][y];
			cusMinIdx = i, cusMinX = x, cusMinY = y;
		}
		else if (dis[x][y] == cusDis) {
			if (x < cusMinX) {
				cusMinIdx = i, cusMinX = x, cusMinY = y;
			}
			else if (x == cusMinX) {
				if (y < cusMinY) {
					cusMinIdx = i, cusMinX = x, cusMinY = y;
				}
			}
		}
	}
	return cusMinIdx;
}
void oilMinus() {
	if (oil < 0) {
		End();
	}
}
void sol() {
	while (1) {
		if (cus.size() == 0)break;
		bfs(taxi.first, taxi.second); 
		int idx = findMinDist();

		oil -= dis[cus[idx].x1][cus[idx].y1];
		oilMinus();

		bfs(cus[idx].x1, cus[idx].y1);
		int nx = cus[idx].x2, ny = cus[idx].y2; 

		if (!visited[nx][ny]) End(); 

		oil -= dis[nx][ny];
		oilMinus();
		oil += (dis[nx][ny] * 2);

		taxi.first = cus[idx].x2, taxi.second = cus[idx].y2;
		cus.erase(cus.begin() + idx);
	}
	cout << oil << '\n';
}

int main() {
	input();
	sol();
	return 0;
}