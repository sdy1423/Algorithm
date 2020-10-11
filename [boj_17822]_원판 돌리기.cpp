#include<cstring>
#include<vector>
#include<iostream>
using namespace std;
int n, m, t, x, d, k;
vector<int> arr[51];
vector<bool> visited[51];
void rotateZero(int idx) {
	int tmp = arr[idx][m - 1];
	for (int i = m - 1; i > 0; i--) {
		arr[idx][i] = arr[idx][i - 1];
	}
	arr[idx][0] = tmp;
}
void rotateOne(int idx) {
	int tmp = arr[idx][0];
	for (int i = 0; i < m - 1; i++) {
		arr[idx][i] = arr[idx][i + 1];
	}
	arr[idx][m - 1] = tmp;
}
void writeVisit(int x1, int y1, int x2, int y2) {
	visited[x1][y1] = true, visited[x2][y2] = true;
}
void findAdjacent() {
	bool ok = false;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!arr[i][j])continue;

			if (i) {
				if (arr[i][j] == arr[i - 1][j]) writeVisit(i, j, i - 1, j), ok = true;
			}

			if (i != n - 1) {
				if (arr[i][j] == arr[i + 1][j]) writeVisit(i, j, i + 1, j), ok = true;
			}

			if (j) {
				if (arr[i][j] == arr[i][j - 1]) {
					writeVisit(i, j, i, j - 1), ok = true;
				}
			}
			else {
				if (arr[i][j] == arr[i][m - 1]) {
					writeVisit(i, j, i, m - 1), ok = true;
				}
			}

			if (j != m - 1) {
				if (arr[i][j] == arr[i][j + 1]) {
					writeVisit(i, j, i, j + 1), ok = true;
				}
			}
		}
	}

	if (ok) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visited[i][j]) {
					arr[i][j] = 0;
				}
			}
		}
	}
	else {
		int sum = 0, bot = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j]) {
					sum += arr[i][j];
					bot++;
				}
			}
		}
		double arv = (double)sum / (double)bot;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!arr[i][j])continue;
				if (arv < (double)arr[i][j])arr[i][j]--;
				else if (arv > (double)arr[i][j])arr[i][j]++;
			}
		}
	}
}
void sol(int x, int d, int k) {
	for (int i = x; i <= n; i = i + x) {
		if (d == 0) {
			for (int j = 0; j < k; j++) {
				rotateZero(i - 1);
			}
		}
		else {
			for (int j = 0; j < k; j++) {
				rotateOne(i - 1);
			}
		}
	}
	findAdjacent();
}
void printAns() {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans += arr[i][j];
		}
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m >> t;

	for (int i = 0; i < n; i++) {
		arr[i].resize(m, 0);
		visited[i].resize(m, false);
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}


	for (int i = 0; i < t; i++) {
		cin >> x >> d >> k;
		sol(x, d, k);
	}


	printAns();

	return 0;
}