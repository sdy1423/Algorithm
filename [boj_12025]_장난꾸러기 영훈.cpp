#include<iostream>
#include<string>
#include<cmath>
#include<vector>
using namespace std;
typedef long long ll;
string input, ans;
ll k, cnt;
vector<pair<int, int>> vec; //위치, 종류(1:1or6,2:2or7)
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> input >> k;
	k -= 1;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '1' || input[i] == '6') vec.push_back({ i,1 });
		else if (input[i] == '2' || input[i] == '7') vec.push_back({ i,2 });
	}
	cnt = vec.size();
	ans = input;
	if (k + 1 > (ll)pow(2, cnt)) {
		cout << -1 << '\n';
	}
	else {
		for (int i = 0; i < vec.size(); i++) {
			if ((k & (1LL << i)) == (1LL << i)) {
				if (vec[cnt - 1 - i].second == 1) {
					ans[vec[cnt - 1 - i].first] = '6';
				}
				else {
					ans[vec[cnt - 1 - i].first] = '7';
				}
			}
			else {
				if (vec[cnt - 1 - i].second == 1) {
					ans[vec[cnt - 1 - i].first] = '1';
				}
				else {
					ans[vec[cnt - 1 - i].first] = '2';
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}