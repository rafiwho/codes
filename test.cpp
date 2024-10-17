#include <bits/stdc++.h>
using namespace std;
template <typename D> vector<D> get_div(D n) {
	vector<D> divs;
	for (D i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			divs.push_back(i);
			if (n ^ i * i) {
				divs.push_back(n / i);
			}
		}
	}
	return divs;
}

void tcase() {
	int a, b, l, r;
	cin >> a >> b >> l >> r;
	/*
	 count the number of pair such that gcd(x,y) == a and lcm(x,y) == b where (a,b,l,r <= 10 ^ 12)
	 gcd(x,y) == a so x,y must be a multiple of a
	 x = a * m
	 y = a * k
	 and gcd(m,k) should be 1
	 a * b = x * y --- (1)
	 a * b = (a * m) * (a * k)
	 a * b = a^2  * m * k
	 b = a * m * k
	 m * k = b / a (so a|b)
	*/

	auto div_a = get_div(a);
	int pr = 0;

	int target = b / a;
	for (int m : div_a) {
		// potential m
		int k = target / m;
		if (gcd(k, m) == 1) {
			int64_t x = 1LL * a * m;
			int64_t y = 1LL * a * k;
			if (x >= l and x <= r and y >= l and y <= r) {
				++pr;
			}
		}
	}
	cout << pr << '\n';
}
int32_t main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int32_t t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}