#include<iostream>
#include<string>
#include<stack>
#include<set>
using namespace std;
string input, ret;
int brk_cnt;
bool visited[201];
int match[201];
set<string> ans;
void find_ans(int cur) {
	if (cur == input.size()) {
		ans.insert(ret);
		return;
	}
	if (input[cur] == '(') {
		visited[match[cur]] = true;
		find_ans(cur + 1);
		visited[match[cur]] = false;
	}
	if (input[cur] == ')' && visited[cur]) {
		find_ans(cur + 1);
	}
	else {
		ret += input[cur];
		find_ans(cur + 1);
		ret.resize(ret.size() - 1);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> input;
	stack<int> st;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '(') {
			st.push(i);
			brk_cnt++;
		}
		else if (input[i] == ')') {
			int idx = st.top();
			st.pop();
			match[idx] = i, match[i] = idx;
		}
	}
	find_ans(0);
	ans.erase(input);
	set<string>::iterator it;
	for (it = ans.begin(); it != ans.end(); it++) {
		cout << *it << '\n';
	}
	return 0;
}