#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;

int main() {
	cin >> n;
	vector<int> arr1(n), arr2;
	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
		vector<int>::iterator it = lower_bound(arr2.begin(), arr2.end(), arr1[i]);
		if (it == arr2.end())arr2.push_back(arr1[i]);
		else *it = arr1[i];
	}
	cout << arr2.size() << '\n';
	return 0;
}