#include<iostream>
#include<cmath>
using namespace std;
double n;
int main() {
	cin >> n;
	n = sqrt(n);
	n *= 4;
	cout << fixed;
	cout.precision(6);
	cout << n << '\n';
}