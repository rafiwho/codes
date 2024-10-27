#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int LOG = __bit_width(N) + 1;

vector<int> v[N];
vector<int> lev(N);
vector<vector<int>> up(N, vector<int>(LOG));

void dfs(int a, int parent) {
	up[a][0] = parent;
	for (int i = 1; i < LOG; ++i) {
		if (up[a][i - 1] != -1)
			up[a][i] = up[up[a][i - 1]][i - 1];
		else
			up[a][i] = -1;
	}
	for (int b : v[a]) {
		if (b != parent) {
			lev[b] = lev[a] + 1;
			dfs(b, a);
		}
	}
}

int get_lca(int a, int b) {
	if (lev[a] < lev[b])
		swap(a, b);

	int dif = lev[a] - lev[b];

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
			if (node == -1)
				break;
		}
	}
	return node;
}

void tcase() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		v[i].clear();
		lev[i] = 0;
		fill(up[i].begin(), up[i].end(), -1);
	}

	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	int q;
	cin >> q;

	lev[1] = 0;
	dfs(1, -1);

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	// cin >> t;

	while (t--) {
		tcase();
	}

	return 0;
}
