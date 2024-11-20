#include <bits/stdc++.h>
using namespace std;

map<int, int64_t> m;
void ins(int a, int64_t b) {
	auto it = m.lower_bound(a);
	if (it != end(m) && it->second >= b) return;
	it = m.insert(it, {a, b});
	it->second = b;
	while (it != begin(m) && prev(it)->second <= b) m.erase(prev(it));
}
int64_t query(int x) {
	auto it = m.lower_bound(x);
	return it == end(m) ? 0 : it->second;
}
void tcase() {
	int n; cin >> n;

	for (int i = 0; i < n; ++i) {

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

{a, b} {c, d}
abs(a - c) + abs(c - d);