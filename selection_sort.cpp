#include <bits/stdc++.h>
using namespace std;
template<typename T>
void output_vector(const vector<T> &v, bool add_one = false) {
	int start = 0 , end = int(v.size());

	for (int i = start; i < end; i++)
		cout << v[i] + (add_one ? 1 : 0) << " \n"[i == end - 1];
}
void tcase() {
	vector<int>v = {1, 23, 4, 1, 2, 234, 4};
	for (auto i = 0LL; i < int(v.size()); ++i) {
		int mn = v[i], posi = i;
		for (auto j = i + 1; j < int(v.size()); ++j) {
			if (mn > v[j]) {
				mn = v[j];
				posi = j;
			}
		}
		swap(v[i], v[posi]);
	}
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