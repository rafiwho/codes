#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int n;
	cin >> n;
	ll a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll gg = 0;
	int ans = 2 * n;

	for (int i = 0; i < n; i++) {

		gg = __gcd(a[i], gg);

		if (gg == 1) {
			int j = i;
			ll gg2 = 0;

			while (i - j < ans and j >= 0 and gg2 != 1) {
				gg2 = __gcd(a[j], gg2);
				j--;
			}

			ans = min(ans, i - j);
			gg = a[i];
		}

	}
	cout << (ans == 2 * n ? -1 : ans) << '\n';
	return 0;
}