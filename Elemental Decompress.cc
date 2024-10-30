#include <bits/stdc++.h>
using namespace std;

void tcase() {
	int n;
	cin >> n;
	vector<vector<int>>v(n + 1);
	vector<int>vv(n + 1);
	bool f = false;
	for (int i = 1; i <= n; ++i) {
		int x; cin >> x;
		v[x].push_back(i);
		vv[i] = x;
		if (v[x].size() > 2)
			f = true;
	}
	if (f) {
		cout << "NO\n";
		return;
	}
	vector<int>per1(n + 1, -1), per2(n + 1, -1), a(n + 1, -1), b(n + 1, -1);
	for (int x = n; x >= 1; --x) {
		for (auto i : v[x]) {
			if (per1[x] == -1) {
				a[per1[x] = i] = x;
			} else if (per2[x] == -1) {
				b[per2[x] = i] = x;
			}
		}
	}
	for (int x = n, xx = n, yy = n; x >= 1; --x) {
		for (auto i : v[x]) {
			while (per1[xx] != -1) --xx;
			while (per2[yy] != -1) --yy;
			if (a[i] == -1 && xx > 0)
				a[per1[xx] = i] = xx;
			else if (b[i] == -1 && yy > 0)
				b[per2[yy] = i] = yy;
		}
	}
	vector<int>construct(n + 1);
	for (int i = 1; i <= n; ++i) {
		construct[i] = max(a[i], b[i]);
		if (construct[i] != vv[i]) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	for (int i = 1; i <= n; ++i) {
		cout << a[i] << ' ';
	}
	cout << '\n';
	for (int i = 1; i <= n; ++i) {
		cout << b[i] << ' ';
	}
	cout << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	cin >> t;

	while (t-- > 0)
		tcase();
}