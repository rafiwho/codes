using i64 = long long;
int legendre(i64 n, i64 p) { // only if p is prime -> max x such that p^x|n!
	i64 ans = 0;
	while (n) {
		ans += n / p;
		n /= p;
	}
	return ans;
}