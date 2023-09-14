#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define in insert
#define ff first
#define ss second
#define all(x) (x).begin(),(x).end()

const int N = 1e5 + 7;
int n , cat;
vector<int>cats(N);
vector<int>v[N];

int ans = 0;
void dfs(int ver, int cnt, int par = 0) {
	if (cnt > cat)
		return ;

	for (auto child : v[ver]) {
		if (child == par)
			continue;
		dfs(child, cats[child] ? cnt + 1 : 0, ver);
	}

	if (v[ver].size() == 1 && ver != 1)
		ans++;
}

void tcase() {
	cin >> n >> cat;

	for (int i = 1; i <= n; ++i) {
		cin >> cats[i];
	}

	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}

	dfs(1, cats[1]);
	cout << ans << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;

	while (t-- > 0)
		tcase();
}
