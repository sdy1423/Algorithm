#include<iostream>
using namespace std;
int n;
int main() {
	cin >> n;
	for (int i = 0; i <= (n - 1) * 2; i++) {
		if (i <= n - 1) for (int j = 0; j < i; j++)cout << ' ';
		else for (int j = 0; j < (n - 1) * 2 - i; j++)cout << ' ';
		if (i == 0 || i == (n - 1) * 2) for (int j = 0; j < n; j++)cout << "*";
		else {
			cout << "*";
			for (int j = 0; j < n - 2; j++) cout << ' ';
			cout << "*";
		}
		if (i < n - 1) for (int j = 0; j < (n - 1) * 2 - 1 - 2 * i; j++)cout << ' ';
		else if (i > n - 1) for (int j = 0; j < (i - n) * 2 + 1; j++)cout << ' ';
		if (i != n - 1)cout << "*";
		if (i == 0 || i == (n - 1) * 2) for (int j = 0; j < n - 1; j++)cout << "*";
		else {
			for (int j = 0; j < n - 2; j++) cout << ' ';
			cout << "*";
		}
		cout << '\n';
	}
	return 0;
}