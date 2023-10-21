#include <bits/stdc++.h>
using namespace std;
//make all bit to set()
constexpr int N = int(1e5) + 5;
bitset<N>arr;
void sieve() {
	arr[0] = arr[1] = false;
	for (int i = 4; i < N; i += 2)arr[i] = false;
	for (int i = 3; i * i <= N; i += 2) {
		if (arr[i]) {
			for (int j = 2 * i; j < N; j += i) {
				arr[j]  = false;
			}
		}
	}
}
void tcase() {
	int n;
	cin >> n;
	cout << (n < 3 ? 1 : 2) << '\n';
	for (int i = 2; i <= n + 1; ++i) {
		cout << (!arr[i] ? "2 " : "1 ");
	}
	cout << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	arr.set();
	sieve();
	int t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}