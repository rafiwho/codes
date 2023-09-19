#include <bits/stdc++.h>
using namespace std;

void tcase() {
	int n;
	cin >> n;
	vector<int>v;
	int64_t sum = 0;
	for (int i = 0; i < n; ++i) {
		int duration, deadline;
		cin >> duration >> deadline;
		v.push_back(duration);
		sum += deadline;
	}
	sort(v.begin(), v.end());
	int64_t ans = 0;
	for (auto duration : v) {
		ans += duration;
		sum -= ans;
	}
	cout << sum << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}