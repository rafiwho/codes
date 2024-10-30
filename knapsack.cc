#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 1E9;
constexpr int N = 1E6 + 6;
int ans = -INF;
int n , sack;
vector<int>items(N), pr(N);
void knapsack(int i, int weight , int value) {

	if (i > n)
		return;
	else if (i == n) {
		if (weight <= sack) {
			ans = max(ans , value);
		}
		return;
	}

	knapsack(i + 1, weight, value);
	knapsack(i + 1, weight + items[i], value + pr[i]);
};
void tcase() {
	cin >> n >> sack;
	for (int i = 0; i < n; ++i) {
		cin >> items[i] >> pr[i];
	}
	knapsack(0, 0, 0);
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