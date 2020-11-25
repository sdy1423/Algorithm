#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
int n, m, ans = 987654321;
int mp[11][11], time[11][11], visited[11][11];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
vector<pair<int, int>> Candi;
void Input() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mp[i][j];
			if (!mp[i][j]) {
				Candi.push_back({ i,j });
			}
		}
	}
}
void Bfs() {
	memset(time, 0, sizeof(time));
	memset(visited, 0, sizeof(visited));
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	visited[0][0] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue;
			if (visited[nx][ny])continue;
			if (mp[nx][ny] == 1 || (mp[nx][ny] >= 2 && !((time[x][y] + 1) % mp[nx][ny]))) {
				q.push({ nx,ny });
				time[nx][ny] = time[x][y] + 1;
				visited[nx][ny] = true;
			}
		}
	}
	int candi = time[n - 1][n - 1];
	if (visited[n - 1][n - 1] && candi < ans)ans = time[n - 1][n - 1];
}

bool Range(int x, int y) {
	if (mp[x + dx[0]][y + dy[0]] && mp[x + dx[1]][y + dy[1]])return true;
	if (mp[x + dx[2]][y + dy[2]] && mp[x + dx[3]][y + dy[3]])return true;
	return false;
}
void Sol() {
	for (int i = 0; i < Candi.size(); i++) {
		int x = Candi[i].first;
		int y = Candi[i].second;
		if (!Range(x, y))continue;
		cout << "x: " << x << "y: " << y << '\n';
		mp[x][y] = m;
		Bfs();
		mp[x][y] = 0;
	}
}
int main() {
	Input();
	Sol();
	cout << ans << '\n';
	return 0;
}