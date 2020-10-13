#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int a, b, ans;
struct SHARK {
	int x, y, dir;
};
struct FISH {
	int x, y, dir, num;
	bool alive;
};
bool cmp(FISH a, FISH b) {
	return a.num < b.num;
}
int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,-1,-1,-1,0,1,1,1 };
bool rangeChk(int x, int y) {
	return !(x < 0 || y < 0 || x >= 4 || y >= 4);
}
void moveFish(vector<vector<int>>& map, vector<FISH>& fish) {

	for (int i = 1; i < fish.size(); i++) {
		if (fish[i].alive == false)continue;
		int x, y, dir, num;
		x = fish[i].x, y = fish[i].y, dir = fish[i].dir, num = fish[i].num;

		int nx, ny, firstDir = dir;
		while (1) {

			nx = x + dx[dir], ny = y + dy[dir];
			if (!rangeChk(nx, ny) || map[nx][ny] == -1) {
				dir = (dir + 1) % 8;
				if (dir == firstDir)break;
				continue;
			}
			else {
				int nIdx = map[nx][ny]; 
				if (!nIdx) {
					map[nx][ny] = map[x][y];
					map[x][y] = 0;
					fish[i].x = nx, fish[i].y = ny;
					fish[i].dir = dir;
				}
				else {
					map[x][y] = nIdx;
					map[nx][ny] = i;

					fish[i].x = nx, fish[i].y = ny;
					fish[i].dir = dir;
					fish[nIdx].x = x, fish[nIdx].y = y;

				}
				break;
			}
		}
	}
}
void go(SHARK shk, vector<vector<int>>fishMap, vector<FISH> fish, int sum) {
	ans = max(ans, sum);
	moveFish(fishMap, fish);
	int x, y, dir, nx, ny;
	x = shk.x, y = shk.y, dir = shk.dir;

	while (1) {
		nx = x + dx[dir], ny = y + dy[dir];
		if (!rangeChk(nx, ny))break; 
		if (fishMap[nx][ny] > 0) {
			int eatenFishIdx = fishMap[nx][ny];
			fish[eatenFishIdx].alive = false; 
			fishMap[shk.x][shk.y] = 0;
			SHARK shk = { nx,ny,fish[eatenFishIdx].dir };
			fishMap[nx][ny] = -1; 
			go(shk, fishMap, fish, sum + eatenFishIdx);
			fishMap[shk.x][shk.y] = -1;
			fishMap[nx][ny] = eatenFishIdx;
			fish[eatenFishIdx].alive = true;
		}
		x = nx, y = ny; 
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	vector<FISH> fish;
	fish.push_back({ -1,-1,-1,0 });
	SHARK shark;
	vector<vector<int>> fishMap(4, vector<int>(4, 0));
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> a >> b; 
			b--;
			if (!i && !j) {
				shark = { i,j,b };
				fishMap[0][0] = -1;
				sum = a;
				fish.push_back({ i,j,b,a,false });
			}
			else {
				fishMap[i][j] = a;
				FISH Fish;
				Fish.num = a, Fish.x = i, Fish.y = j, Fish.dir = b, Fish.alive = true;
				fish.push_back(Fish);
			}
		}
	}
	sort(fish.begin(), fish.end(), cmp);
	go(shark, fishMap, fish, sum);
	cout << ans << '\n';
	return 0;
}