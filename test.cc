#include <bits/stdc++.h>
using namespace std;
constexpr int mod = 1E9 + 7;
void add(int &a, int b) {
	a = (a + b) % mod;
}
void sub(int &a, int b) {
	a = (a - b + mod) % mod;
}
int mul(int a, int b) {
	return (int64_t(a) * b) % mod;
}
void tcase() {

}
int32_t main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int32_t t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}