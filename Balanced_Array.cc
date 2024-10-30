#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...)
#endif

#define pb push_back
#define in insert
#define ff first
#define ss second
#define all(x) (x).begin(),(x).end()
template<typename T>
void output_vector(const vector<T> &v, bool add_one = false, int start = -1, int end = -1) {
	if (start < 0) start = 0;
	if (end < 0) end = int(v.size());

	for (int i = start; i < end; i++)
		cout << v[i] << ' ' ;
}
void tcase() {
	int n;
	cin >> n;

	if ((n / 2) & 1) {
		cout << "NO\n";
		return ;
	}
	cout << "YES\n";
	std::vector<int> v;

	for (int i = 1; i <= n; ++i) {
		if (!(i & 1)) {
			v.pb(i);
		}
	}

	output_vector(v);
	int sum1 = accumulate(all(v), 0ll);
	int sum2 = 0;

	for (int i = 0; i < int(v.size()) - 1; ++i) {
		cout << v[i] - 1 << " ";
		sum2 += (v[i] - 1);
	}

	cout << sum1 - sum2 << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	cin >> t;

	while (t-- > 0)
		tcase();
}