#include <algorithm>
#include <bits/stdc++.h>
#include <complex>
#include <vector>
using namespace std;
template<typename T>
void output_vector(const vector<T> &v, bool add_one = false) {
	int start = 0 , end = int(v.size());

	for (int i = start; i < end; i++)
		cout << v[i] + (add_one ? 1 : 0) << " \n"[i == end - 1];
}
void tcase() {
	vector<int> v = { -1, -2, 4, 5, 6, -10};
	sort(v.begin(), v.end(), [](auto x, auto y) {
		return abs(x) < abs(y);
	});
	output_vector(v);
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}