#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...)
#endif

void tcase() {
	int n , sack;
	cin >> n >> sack;
	vector<int>items(n), pr(n);

	for (int i = 0; i < n; ++i) {
		cin >> items[i] >> pr[i];
	}

	int ans = INT32_MIN;
	auto knapsack = [&](auto && knapsack , int i, int weight , int value)->void{

		if (i > n)
			return;
		else if (i == n) {
			if (weight <= sack) {
				ans = max(ans , value);
			}
			return;
		}

		knapsack(knapsack, i + 1, weight, value);
		knapsack(knapsack, i + 1, weight + items[i], value + pr[i]);
	};

	knapsack(knapsack, 0, 0, 0);
	cout << ans << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}