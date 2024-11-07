#include <bits/stdc++.h>
using namespace std;
const int N = 6E5 + 5;
int len[N], lnk[N] { -1}, last, sz = 1;
unordered_map<char, int> to[N];

void add(char c) {
	int cur = sz++;
	len[cur] = len[last] + 1;
	int u = last;
	while (u != -1 and !to[u].count(c)) {
		to[u][c] = cur;
		u = lnk[u];
	}
	if (u == -1) {
		lnk[cur] = 0;
	}
	else {
		int v = to[u][c];
		if (len[v] == len[u] + 1) {
			lnk[cur] = v;
		}
		else {
			int w = sz++;
			len[w] = len[u] + 1, lnk[w] = lnk[v], to[w] = to[v];
			while (u != -1 and to[u][c] == v) {
				to[u][c] = w;
				u = lnk[u];
			}
			lnk[cur] = lnk[v] = w;
		}
	}
	last = cur;
}
void clear() {
	for (int i = 0; i < sz; ++i) {
		len[i] = 0;
		lnk[i] = -1;
		to[i].clear();
	}
}
string s;
int64_t dp[N];
int64_t f(int cur) {
	int64_t &ans = dp[cur];
	if (~ans) return ans;
	ans = 1;
	for (auto [ch, nxt] : to[cur]) {
		if (to[cur].count(ch)) {
			ans += f(nxt);
		}
	}
	return ans;
}
void tcase() {
	cin >> s;
	for (char ch : s) {
		add(ch);
	}
	for (int i = 0; i < sz; ++i) {
		dp[i] = -1;
	}
	for (int i = 0; i < 26; ++i) {
		cout << (to[0].count(i + 'a') ? f(to[0][i + 'a']) : 0) << ' ';
	}
}
int32_t main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int32_t t = 1;
	// cin >> t;

	while (t-- > 0)
		tcase();
}