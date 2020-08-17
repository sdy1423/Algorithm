#include <algorithm> 
#include <iostream> 
#include <cmath> 
#include <string> 
using namespace std;
int N, sumNum, aNum, bNum;
string a, b, sum;
int main() {
	cin >> N;
	while (N--)
	{
		sum = "";
		sumNum = 0;
		cin >> a >> b;
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		aNum = stoi(a), bNum = stoi(b);
		sumNum = aNum + bNum;
		sum = to_string(sumNum);
		reverse(sum.begin(), sum.end());
		sumNum = stoi(sum);
		cout << sumNum << '\n';;
	}
}

