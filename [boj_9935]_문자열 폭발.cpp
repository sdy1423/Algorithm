#include<string>
#include<iostream>
using namespace std;
string str1, str2, ans;
char edge;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> str1 >> str2;
	edge = str2[str2.size() - 1];
	for (int i = 0; i < str1.size(); i++) {
		ans += str1[i];
		if (str1[i] == edge) {
			int start = ans.size() - str2.size();
			if (start < 0)continue;
			if (ans.substr(start, str2.size()) == str2) ans.erase(start, str2.size());
		}
	}
	if (ans == "")cout << "FRULA" << '\n';
	else cout << ans << '\n';
	return 0;
}