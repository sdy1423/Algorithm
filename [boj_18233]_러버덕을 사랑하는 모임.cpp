#include<iostream>
#include<vector>
#define f first
#define s second
using namespace std;
typedef pair<int, int> P;
int n, p, e, ans[21];
vector<P> MinMax;
bool isAnswer;
void FindAns(int bits) {
	int Min = 0, Max = 0;
	for (int i = 0; i < n; i++) {
		if (bits & (1 << i)) {
			Min += MinMax[i].f;
			Max += MinMax[i].s;
		}
	}
	if (Min <= e && Max >= e) {
		isAnswer = true;
		int tot = e;
		for (int i = 0; i < n; i++) {
			if (bits & (1 << i)) {
				ans[i] = MinMax[i].f;
				tot -= MinMax[i].f;
			}
		}
		for (int i = 0; i < n && tot>0; i++) {
			if (bits & (1 << i)) {
				if (tot > MinMax[i].s - MinMax[i].f) {
					tot -= MinMax[i].s - MinMax[i].f;
					ans[i] = MinMax[i].s;
				}
				else {
					ans[i] += tot;
					tot = 0;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
	}
	else return;
}
void Find(int idx, int cnt, int bits) {
	if (cnt == p && !isAnswer) {
		FindAns(bits);
		return;
	}
	if (idx == n)return;
	Find(idx + 1, cnt, bits);
	Find(idx + 1, cnt + 1, bits | (1 << idx));
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> p >> e;
	MinMax.resize(n);
	for (int i = 0; i < n; i++) cin >> MinMax[i].f >> MinMax[i].s;
	Find(0, 0, 0);
	if (!isAnswer)cout << -1 << '\n';
	return 0;
}