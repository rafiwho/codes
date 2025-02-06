#include <bits/stdc++.h>
using namespace std;
const int N = 250000 * 32;
const int A = 26;
int id = 1;
int nxt[N][A];
set<int>st[N];
void add(string s, int i) {
	reverse(s.begin(), s.end());
	int cur = 1;
	st[cur].insert(i);
	for (char ch : s) {
		ch -= 'a';
		if (nxt[cur][ch] == 0) {
			nxt[cur][ch] = ++id;
		}
		cur = nxt[cur][ch];
		st[cur].insert(i);
	}
}
int Get_Id(string s) {
	reverse(s.begin(), s.end());
	int cur = 1;
	for (char ch : s) {
		ch -= 'a';
		if (nxt[cur][ch] && !st[nxt[cur][ch]].empty()) {
			cur = nxt[cur][ch];
		} else {
			return *st[cur].begin();
		}
	}
	return *st[cur].begin();
}
void rem(string s, int i) {
	reverse(s.begin(), s.end());
	int cur = 1;
	st[cur].erase(i);
	for (char ch : s) {
		ch -= 'a';
		cur = nxt[cur][ch];
		st[cur].erase(i);
	}
}
void tcase() {
	string s;
	bool yo = true;
	vector<string>L, Q;
	while (getline(cin, s)) {
		if (yo && s != "") {
			L.push_back(s);
		} else {
			if (s == "") {
				yo = false;
			} else {
				Q.push_back(s);
			}
		}
	}
	sort(L.begin(), L.end());
	std::map<string, int> id;
	for (int i = 0; i < L.size(); ++i) {
		id[L[i]] = i;
		add(L[i], i);
	}
	for (int i = 0; i < Q.size(); ++i) {
		if (id.count(Q[i]))
			rem(Q[i], id[Q[i]]);
		cout << L[Get_Id(Q[i])] << '\n';
		if (id.count(Q[i]))
			add(Q[i], id[Q[i]]);
	}

}
int32_t main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int32_t t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}