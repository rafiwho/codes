#include <bits/stdc++.h>
using namespace std;

void tcase() {
	vector<int>v = {2, 3, 4, 1, 3};
	for (auto i = 1LL; i < int(v.size()); ++i) {
		int temp  = v[i];
		int j = i - 1;
		while (j >= 0 && v[j] > temp) {
			v[j + 1] = v[j];
			j--;
		}
		v[j + 1] = temp;
	}
	for (auto x : v)
		cout << x << ' ';
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}