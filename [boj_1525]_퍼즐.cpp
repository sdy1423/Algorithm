#include<iostream>
#include<string>
#include<queue>
#include<map>
using namespace std;
int input, tmp;
queue<int> q;
map<int, int> m;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void bfs() {
	q.push(input);
	m[input] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == 123456789)break;
		string str = to_string(cur);
		int nine = str.find('9');
		int x = nine / 3, y = nine % 3;

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir], ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= 3 || ny >= 3)continue;
			int next = nx * 3 + ny;
			string temp = str;
			swap(temp[nine], temp[next]);
			int n = stoi(temp);
			if (!m.count(n)) {
				m[n] = m[cur] + 1;
				q.push(n);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 9; i++) {
		cin >> tmp;
		if (tmp == 0)tmp = 9;
		input *= 10;
		input += tmp;
	}
	bfs();
	if (!m.count(123456789)) cout << -1 << '\n';
	else cout << m[123456789] << '\n';
	return 0;
}