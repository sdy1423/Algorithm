#include<iostream>
#include<string>
using namespace std;
int n;
string str;
int find(char c) {
	if (c == 'A')return 0;
	else if (c == 'G')return 1;
	else if (c == 'C')return 2;
	else if (c == 'T')return 3;
}
char map[4][4] = {
{'A','C','A','G'},
{'C','G','T','A'},
{'A','T','C','G'},
{'G','A','G','T'}
};
char go(int num, char last) {
	if (!num) {
		return map[find(str[num])][find(last)];
	}
	char tmp = map[find(str[num])][find(last)];
	return go(num - 1, tmp);
}
int main() {
	cin >> n;
	cin >> str;
	char last = str[str.size() - 1];
	cout << go(n - 2, last) << '\n';
	return 0;
}