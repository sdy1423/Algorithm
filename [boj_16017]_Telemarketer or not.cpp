#include<iostream>
using namespace std;
int a, b, c, d;
void ans() {
	cout << "answer" << '\n';
}
void ign() {
	cout << "ignore" << '\n';
}
int main() {
	cin >> a >> b >> c >> d;
	if ((a == 9 || a == 8) && (d == 9 || d == 8)) {
		if (b == c) ign();
		else ans();
	}
	else {
		ans();
	}
	return 0;
}