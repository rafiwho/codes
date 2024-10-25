#include <bits/stdc++.h>
using namespace std;
const int N = 1E6; // change
const int K = 26;

struct AhoCorasick {
	struct ver {
		int nxt[K];
		ver() {
			fill(begin(nxt), end(nxt), 0);
		}
	};

	vector<ver> trie;
	vector<int> slnk, dp, end_at;

	AhoCorasick() : slnk(N), dp(N), end_at(N) {
		trie.emplace_back(); // Initialize root node
	}

	void add(string &s, int i) {
		int v = 0;
		for (char ch : s) {
			int c = ch - 'a';
			if (trie[v].nxt[c] == 0) {
				trie[v].nxt[c] = trie.size();
				trie.emplace_back();
			}
			v = trie[v].nxt[c];
		}
		end_at[i] = v;
	}

	void build() {
		queue<int> q;
		q.push(0);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int c = 0; c < K; ++c) {
				int v = trie[u].nxt[c];
				if (v == 0) continue;  // No node

				q.push(v);
				if (u == 0) continue;  // Root node

				int cur = slnk[u];
				while (cur && trie[cur].nxt[c] == 0) cur = slnk[cur];
				slnk[v] = trie[cur].nxt[c];
			}
		}
	}

	void trav(string &text) {
		int u = 0;
		for (char c : text) {
			c -= 'a';
			while (u && trie[u].nxt[c] == 0) u = slnk[u];
			u = trie[u].nxt[c];
			dp[u]++;
		}
	}

	void clear() {
		fill(begin(dp), begin(dp) + trie.size(), 0);
		fill(begin(slnk), begin(slnk) + trie.size(), 0);
		fill(begin(end_at), begin(end_at) + trie.size(), 0);
		trie.clear();
		trie.emplace_back();
	}
};

void tcase() {
	int n; string text;
	cin >> n >> text;
	vector<string> v(n);
	AhoCorasick ac;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		ac.add(v[i], i);
	}
	ac.build();
	ac.trav(text);

	for (int i = 0; i < n; ++i) {
		cout << ac.dp[ac.end_at[i]] << '\n';
	}
	ac.clear();
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int32_t t = 1, cs = 1;
	cin >> t;

	while (t-- > 0) {
		cout << "Case " << cs++ << ":\n";
		tcase();
	}
}
