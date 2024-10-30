#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
vector<ll>T;

void update(ll N, ll st, ll en, ll i, ll val) {
	if (st == en) {
		T[N] = val;
		return;
	}
	ll mid = (st + en) >> 1;
	if (i <= mid)
		update(N << 1, st, mid, i, val);
	else
		update(N << 1 | 1, mid + 1, en, i, val);

	T[N] = gcd(T[N << 1], T[N << 1 | 1]);
}
ll query(ll N, ll st, ll en, ll l, ll r) {
	if (st > r || en < l)
		return 0;
	if (st >= l && en <= r)
		return T[N];

	ll mid = (st + en) >> 1;
	ll q1  = query(N << 1, st, mid, l, r);
	ll q2 = query(N << 1 | 1, mid + 1, en, l, r);
	return gcd(q1, q2);
}
void tcase() {
	ll n;
	cin >> n;
	T.resize(3 * n, 0);
	unordered_multimap<ll, ll>mp;
	for (ll i = 0; i < n; ++i) {
		char ch; ll x; cin >> ch >> x;
		if (ch == '+') {
			mp.insert({x, i});
			update(1, 0, n - 1, i, x);
			cout << (T[1] ? T[1] : 1) << '\n';
		} else {
			auto posi = mp.find(x);
			update(1, 0, n - 1, posi->second, 0);
			mp.erase(posi);
			cout << (T[1] ? T[1] : 1) << '\n';
		}
	}
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}
