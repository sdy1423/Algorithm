#include<iostream>
#include<string>
using namespace std;
int n, k, bCnt, aCnt, Move, cnt;
string str = "";
int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	while (str.size() < n) str += "B";
	bCnt = n;
	for (int i = 0; i < n; i++) {
		str[i] = 'A', bCnt--, aCnt++;
		if (bCnt * aCnt > k) {
			Move = i;
			break;
		}
		else if (bCnt * aCnt == k) {
			cout << str << '\n';
			return 0;
		}
	}
	cnt = aCnt * bCnt;
	for (int i = Move + 1; i < n; i++) {
		str[i - 1] = 'B', str[i] = 'A', cnt--;
		if (cnt == k) {
			cout << str << '\n';
			return 0;
		}
	}
	cout << -1 << '\n';
	return 0;
}