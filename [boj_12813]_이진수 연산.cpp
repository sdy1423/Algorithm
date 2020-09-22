#include<iostream>
#include<string>
using namespace std;
string str1, str2;
int n;
int main() {
	cin >> str1 >> str2;
	for (int i = 0; i < str1.size(); i++) {
		n = (str1[i] - '0') && (str2[i] - '0');
		cout << n;
	}
	cout << '\n';
	for (int i = 0; i < str1.size(); i++) {
		n = (str1[i] - '0') || (str2[i] - '0');
		cout << n;
	}
	cout << '\n';
	for (int i = 0; i < str1.size(); i++) {
		n = (str1[i] - '0') ^ (str2[i] - '0');
		cout << n;
	}
	cout << '\n';
	for (int i = 0; i < str1.size(); i++) {
		if (str1[i] == '0')cout << 1;
		else cout << 0;
	}
	cout << '\n';
	for (int i = 0; i < str1.size(); i++) {
		if (str2[i] == '0')cout << 1;
		else cout << 0;
	}
	cout << '\n';
	return 0;
}