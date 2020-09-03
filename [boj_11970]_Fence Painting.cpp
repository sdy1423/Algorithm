#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int a, b, c, d, ans = 0;
	cin >> a >> b >> c >> d;
	if (a == c && b == d)ans = d - c;
	else if (a == c && b != d)ans = max(b, d) - a;
	else if (a != c && b == d)ans = d - min(a, c);
	else if (a > c)
		if (d < a)ans = b - a + d - c;
		else ans = max(d, b) - c;
	else
		if (b < c)ans = b - a + d - c;
		else ans = max(d, b) - a;
	cout << ans << '\n';
	return 0;
}