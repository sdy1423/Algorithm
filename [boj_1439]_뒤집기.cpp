#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	string str;
	cin >> str;
	int zero = 0, one = 0;
	for (int i = 1; i < str.size(); i++) {
		if (str[i] != str[i - 1]) {
			if (str[i - 1] == '0')zero += 1;
			else one += 1;
		}
		else {
			continue;
		}
	}
	if (str[str.size() - 1] == '0')zero += 1;
	else one += 1;
	cout << min(zero, one) << '\n';
	return 0;
}