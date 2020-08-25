#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
#define MOD 1000000007
#define MAX 1000001
typedef long long ll;
int n, m, k;
ll init[MAX];
vector<pair<pair<ll, ll>, ll>> cmd;
vector<ll> tree;
ll a, b, c;
void Input() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)cin >> init[i];
	for (int i = 0; i < m + k; i++) {
		cin >> a >> b >> c;
		cmd.push_back({ { a,b }, c });
	}
}
void TreeSize() {
	int tree_height = (int)ceil(log2(n));
	int tree_size = (1 << (tree_height + 1));
	tree.resize(tree_size);
}
ll MakeTree(int node, int start, int end) {
	if (start == end)return tree[node] = init[start] % MOD;
	int mid = (start + end) / 2;
	ll l = MakeTree(node * 2, start, mid);
	ll r = MakeTree(node * 2 + 1, mid + 1, end);
	return tree[node] = (l * r) % MOD;
}
ll Update(int node, int start, int end, int idx, ll val) {
	if (start > idx || end < idx)return tree[node];
	if (start == end)return tree[node] = val;
	int mid = (start + end) / 2;
	ll l = Update(node * 2, start, mid, idx, val);
	ll r = Update(node * 2 + 1, mid + 1, end, idx, val);
	return tree[node] = (l * r) % MOD;
}
ll Multiple(int node, int start, int end, int left, int right) {
	if (start > right || end < left)return 1;
	if (left <= start && end <= right)return tree[node];
	int mid = (start + end) / 2;
	ll l = Multiple(node * 2, start, mid, left, right);
	ll r = Multiple(node * 2 + 1, mid + 1, end, left, right);
	return (l * r) % MOD;
}
void Sol() {
	for (int i = 0; i < cmd.size(); i++) {
		ll A, B, C;
		A = cmd[i].first.first;
		B = cmd[i].first.second;
		C = cmd[i].second;
		if (A == 1) Update(1, 0, n - 1, B - 1, C);
		else cout << Multiple(1, 0, n - 1, B - 1, C - 1) % MOD << '\n';
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	Input();
	TreeSize();
	MakeTree(1, 0, n - 1);
	Sol();
	return 0;
}
