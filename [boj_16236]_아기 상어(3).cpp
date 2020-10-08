#include<queue>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int n, m, sec;
bool visited[21][21];
int dis[21][21], map[21][21];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
int eatenCnt;

struct SHARK {
	int x, y, size;
};
vector<SHARK>shark;
SHARK baby;

void input() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				baby = { i,j,2 };
				map[i][j] = 0;
			}
			else if (map[i][j]) {
				shark.push_back({ i,j, map[i][j] });
			}
		}
	}
}

void bfs() {
	queue<pair<int, int>> qu;
	memset(visited, false, sizeof(visited));
	memset(dis, 0, sizeof(dis));

	visited[baby.x][baby.y] = true;
	dis[baby.x][baby.y] = 0;
	qu.push({ baby.x,baby.y });

	while (!qu.empty()) {
		int x = qu.front().first;
		int y = qu.front().second;
		qu.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue;
			if (visited[nx][ny])continue;
			if (baby.size < map[nx][ny])continue;
			visited[nx][ny] = true;
			dis[nx][ny] = dis[x][y] + 1;
			qu.push({ nx,ny });
		}
	}

}
int findMinDis() {
	int idx = -1, dist = 987654321, curX = 0, curY = 0;
	for (int i = 0; i < shark.size(); i++) {

		if (shark[i].size >= baby.size)continue;

		int X = shark[i].x;
		int Y = shark[i].y;

		if (!visited[X][Y])continue;

		int tmpDist = dis[X][Y];

		if (dist > tmpDist) {
			idx = i, curX = X, curY = Y, dist = tmpDist;
		}
		else if (dist == tmpDist) {
			if (curX > X) {
				idx = i, curX = X, curY = Y, dist = tmpDist;
			}
			else if (curX == X) {
				if (curY > Y) {
					idx = i, curX = X, curY = Y, dist = tmpDist;
				}
			}
		}
	}
	return idx;
}
void changeDetail(int idx) {
	baby.x = shark[idx].x;
	baby.y = shark[idx].y;
	map[shark[idx].x][shark[idx].y] = 0;
	shark.erase(shark.begin() + idx);
	eatenCnt++;
	if (baby.size == eatenCnt) {
		baby.size++, eatenCnt = 0;
	}
}
void checkMap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}
void sol() {
	int idx = -1;
	while (1) {
		if (shark.empty())break;
		else {
			bfs();
			idx = findMinDis();
			if (idx == -1)break;
			sec += dis[shark[idx].x][shark[idx].y];
		}
		changeDetail(idx);
		//checkMap();
	}
	cout << sec << '\n';
}
int main() {
	input();
	sol();
	return 0;
}