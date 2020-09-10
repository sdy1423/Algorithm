#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool visited[2001];
int n, tmp;
int main() {
	cin >> n;
	vector<int> num;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp < 0) {
			int ch = -tmp + 1000;
			if (!visited[ch]) {
				visited[ch] = true;
				num.push_back(tmp);
			}
		}
		else {
			if (!visited[tmp]) {
				visited[tmp] = true;
				num.push_back(tmp);
			}
		}
	}
	sort(num.begin(), num.end());
	for (int i = 0; i < num.size(); i++) {
		cout << num[i] << ' ';
	}
	cout << '\n';
	return 0;
}