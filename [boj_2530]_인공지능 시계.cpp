#include<iostream>
using namespace std;
int a, b, c, d, h, m, s;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> a >> b >> c >> d;
	h = (d / 3600);
	if (h) d %= (3600 * h);
	m = d / 60;
	if (m)d %= (60 * m);
	s = d;
	h += a, m += b, s += c;
	if (s >= 60) {
		int tmp = (s / 60);
		m += tmp;
		s %= (60 * tmp);
	}
	if (m >= 60) {
		int tmp = (m / 60);
		h += tmp;
		m %= (60 * tmp);
	}
	if (h >= 24) h %= 24;
	cout << h << ' ' << m << ' ' << s << '\n';
}