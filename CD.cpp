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

int n , k , sum = 0 , mx = INT_MIN ;
vector<int>ans , checker;

void func(int  i, vector<int>&v) {
	if (sum <= n && sum > mx) {
		mx = sum;
		ans = checker;
	}
	for (int m = i; m < k; ++m) {
		if (sum + v[m] <= n) {
			sum += v[m];
			checker.pb(v[m]);
			func(m + 1 , v);
			sum -= v[m];
			checker.pop_back();
		}
	}
}
template<typename T>
void output_vector(const vector<T> &v, bool add_one = false, int start = -1, int end = -1) {
	if (start < 0) start = 0;
	if (end < 0) end = int(v.size());

	for (int i = start; i < end; i++)
		cout << v[i] + (add_one ? 1 : 0) << ' ';
}
void tcase() {
	while (cin >> n >> k) {
		std::vector<int> v(k);

		for (int i = 0; i < k; ++i) {
			cin >> v[i];
		}

		func(0, v);
		output_vector(ans);
		cout << "sum:" << accumulate(all(ans), 0ll) << '\n';

		ans.clear();
		checker.clear();
		sum = 0 , mx = INT_MIN;
	}
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}