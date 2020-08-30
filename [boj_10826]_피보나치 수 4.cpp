#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
int n;
string visited[10001];
string sum(string a, string b) {
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int a_size = a.size(), b_size = b.size();
	if (a_size < b_size) {
		for (int i = 0; i < b_size - a_size; i++)
			a.push_back('0');
	}
	else if (a_size > b_size) {
		for (int i = 0; i < a_size - b_size; i++)
			b.push_back('0');
	}
	char over;
	string s;
	for (int i = 0; i < a.size(); i++) {
		int tmp = a[i] - '0' + b[i] - '0';
		if (i != 0)tmp += (over - '0');
		s.push_back(tmp % 10 + '0');
		over = (tmp / 10) + '0';
	}
	if (over != '0')s.push_back(over);
	reverse(s.begin(), s.end());
	return s;
}
string fibo(int idx) {
	if (visited[idx] != "-1")return visited[idx];
	return visited[idx] = sum(fibo(idx - 1), fibo(idx - 2));
}
int main() {
	cin >> n;
	for (int i = 0; i <= n; i++) visited[i] = "-1";
	visited[0] = '0', visited[1] = '1';
	cout << fibo(n) << '\n';
	return 0;
}