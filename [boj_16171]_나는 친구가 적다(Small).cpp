#include<iostream>
#include<string>
#include<vector>
using namespace std;
string str1, str2, tmp;
char start;
int ans = 0;
vector<string> vec;
bool check(string str) {
	return str == str2;
}
int main() {
	cin >> str1 >> str2;
	start = str2[0];
	bool ok = false;
	for (int i = 0; i < str1.size(); i++) {
		if (str1[i] >= '0' && str1[i] <= '9')continue;
		for (int j = 0; j < vec.size(); j++) {
			vec[j] += str1[i];
			if (check(vec[j])) {
				cout << 1 << '\n';
				return 0;
			}
		}
		if (ok)break;
		if (str1[i] == start) {
			tmp = str1[i], vec.push_back(tmp);
			if (check(tmp)) {
				cout << 1 << '\n';
				return 0;
			}
		}
	}
	cout << 0 << '\n';
	return 0;
}