ll geometric_Sum() {
	ll a, r, n; cin >> a >> r >> n; //a = first value r = ratio, n = n-term
	ll res = BigMod(r, n);
	ll numara = (a * (1 - res)) % MOD;
	numara = (numara + MOD) % MOD;
	ll deno = ((1 - r) % MOD + MOD) % MOD;
	ll ans = (numara * BigMod(deno, MOD - 2)) % MOD;
	return ans;
}