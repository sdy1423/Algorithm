#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
int ans, n, m, map[301][301], map2[301][301], dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
bool visited[301][301];
void BFS(int x, int y, int tmp) {
	queue<pair<int, int>>q;
	q.push({ x,y });
	visited[x][y] = true;
	map2[x][y] = tmp;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir], ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
			if (!visited[nx][ny] && map[nx][ny] && !map2[nx][ny]) {
				visited[nx][ny] = true, map2[nx][ny] = tmp;
				q.push({ nx,ny });
			}
		}
	}
}
bool Region() { //BFS로 빙산 덩어리 개수 카운트 
	memset(visited, false, sizeof(visited));
	memset(map2, false, sizeof(map2));
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && map[i][j] && !map2[i][j]) {
				BFS(i, j, ++tmp);
			}
		}
	}
	if (tmp > 1)return false;
	else return true;
}
void Spread() {
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j]) {
				visited[i][j] = true;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!map[i][j] && !visited[i][j]) {
				for (int dir = 0; dir < 4; dir++) {
					int nx = i + dx[dir], ny = j + dy[dir];
					if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
					if (map[nx][ny])map[nx][ny] -= 1;
				}
			}
		}
	}
	//visited는 높이를 줄이는 과정에서 생긴 바닷물(0)이 높이를 줄이는 것 방지
}
bool check() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j]) return true;
		}
	}
	return false;
}
void Sol() {
	while (1) {
		ans += 1;
		Spread(); //빙산의 높이가 줄어든다.
		if (!check()) {//빙산이 다 녹았는지 체크
			ans = 0;
			break;
		}
		if (!Region())break; //빙산의 덩어리 개수를 센다. (2덩이 이상이면 종료)
	}
}
void Input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	Input();
	Sol();
	cout << ans << '\n';
	return 0;
}