#include<iostream>
#include<algorithm>
using namespace std;
int n;
int curMin[3], curMax[3], tmpMin[3], tmpMax[3], val[3];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> val[0] >> val[1] >> val[2];
		for (int j = 0; j < 3; j++) {
			tmpMin[j] = val[j] + min(curMin[1], (j == 1) ? min(curMin[0], curMin[2]) : curMin[j]);
			tmpMax[j] = val[j] + max(curMax[1], (j == 1) ? max(curMax[0], curMax[2]) : curMax[j]);
		}
		for (int j = 0; j < 3; j++) {
			curMin[j] = tmpMin[j];
			curMax[j] = tmpMax[j];
		}
	}

	cout << *max_element(curMax, curMax + 3) << ' ';
	cout << *min_element(curMin, curMin + 3) << '\n';

	return 0;
}