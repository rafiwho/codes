#include "bits/stdc++.h"
using namespace std;

const int N = 35;
std::vector<int> v[N];
bool vis[N];

int char_to_ith_int(char ch) {
	return int(ch - 64);
}

void dfs(int ver) {
	vis[ver] = true;
	for (auto child : v[ver]) {
		if (!vis[child]) {
			dfs(child);
		}
	}
}

void tcase() {
	string s;
	int n;

	while (getline(cin , s) && int(s.size())) {
		if (int(s.size()) != 1) {
			int a = char_to_ith_int(s[0]);
			int b = char_to_ith_int(s[1]);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		if (int(s.size()) == 1)
			n = char_to_ith_int(s[0]);
	}
	int cnt  = 0;
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			dfs(i);
			cnt++;
		}
	}

	cout << cnt << '\n';

	for (int i = 0; i < 35; ++i) {
		v[i].clear();
		vis[i] = false;
	}
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	cin >> t;
	cin.ignore();
	cin.ignore();

	bool xx = false;
	while (t-- > 0) {
		if (xx)
			cout << '\n';
		tcase();
		xx = true;
	}
}