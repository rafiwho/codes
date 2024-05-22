#include <bits/stdc++.h>
using namespace std;
const int N = 1E5 + 5;
const int LOG = __bit_width(N);

vector<int>v[N];
vector<int>depth(N);
vector<vector<int>>up(N, vector<int>(LOG));

void dfs(int a) {
	for (int b : v[a]) {
		depth[b] = depth[a] + 1;
		up[b][0] = a;
		for (int i = 1; i < LOG; ++i) {
			up[b][i] = up[up[b][i - 1]][i - 1];
		}
		dfs(b);
	}
}

int get_lca(int a, int b) {
	if (depth[a] < depth[b])
		swap(a, b);
	int dif = depth[a] - depth[b];
	for (int k = LOG - 1; k >= 0; --k) {
		if (dif & (1 << k))
			a = up[a][k];
	}

	if (a == b)
		return a;

	for (int k = LOG - 1; k >= 0; --k) {
		if (up[a][k] != up[b][k]) {
			a = up[a][k];
			b = up[b][k];
		}
	}

	return up[a][0];
}

int get_kth_ancestor(int node, int k) {
	for (int i = 0; i < LOG; ++i) {
		if (k & (1 << i)) {
			node = up[node][i];
			if (node == 0)
				break;
		}
	}
	return node == 0 ? -1 : node;
}
auto tcase()->void{
}
auto main()->int32_t{

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int32_t t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}