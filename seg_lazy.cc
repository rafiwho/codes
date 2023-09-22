using ll = int64_t;
vector<ll>T, lazy;
void update(ll N, ll s, ll e, ll l, ll r, ll x) {
	if (s > r || e < l) {
		return;
	}
	if (s >= l && e <= r) {
		T[N] += (e - s + 1) * x;
		lazy[N] += x;
		return;
	}
	ll m = (s + e) >> 1;
	update(N << 1, s, m, l, r, x);
	update(N << 1 | 1, m + 1, e, l, r, x);
	T[N] = T[N << 1] + T[N << 1 | 1] + (e - s + 1) * lazy[N];
}
ll query(ll N, ll s, ll e, ll l, ll r, ll carry = 0) {
	if (s > r || e < l) {
		return 0;
	}
	if (s >= l && e <= r) {
		return T[N] + carry * (e - s + 1);
	}
	ll m = (s + e) >> 1;
	ll q1 = query(N << 1, s, m, l, r, carry + lazy[N]);
	ll q2 = query(N << 1 | 1, m + 1, e, l, r, carry + lazy[N]);
	return q1 + q2;
}