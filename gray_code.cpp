#include <bits/stdc++.h>
using namespace std;
/*
 Let's look at the bits of number and the bits of number G(n). Notice that i-th bit of G(n)equals 1 only when i-th bit of n equals 1 and i + 1-th bit equals 0 or the other way around (i-th bit equals 0 and i + 1$-th bit equals 1). Thus, G(n) = n \oplus (n >> 1)
*/
int g (int n) {
	return n ^ (n >> 1);
}
void tcase() {
	int n; cin >> n;
	for (int i = 0; i < 1 << n; ++i) {
		cout << (bitset<31>(g(i)).to_string().substr(31 - n)) << '\n';
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