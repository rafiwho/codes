#include "bits/stdc++.h"
using namespace std;


#define pb push_back
#define in insert
#define ff first
#define ss second
#define all(x) (x).begin(),(x).end()
struct FenwickTree {
	vector<int> bit;  // binary indexed tree
	int n;

	FenwickTree(int n) {
		this->n = n;
		bit.assign(n, 0);
	}

	FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
		for (size_t i = 0; i < a.size(); i++)
			add(i, a[i]);
	}

	int sum(int r) {
		int ret = 0;
		for (; r >= 0; r = (r & (r + 1)) - 1)
			ret = __gcd(ret, bit[r]);
		return ret;
	}

	int sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}

	void add(int idx, int delta) {
		for (; idx < n; idx = idx | (idx + 1))
			bit[idx] *= delta;
	}
};
void tcase() {
	int n , m;
	cin >> n >> m;

	FenwickTree ft(n);

	for (int i = 0; i < n; ++i) {
		ft.add(0, 0);
	}

	for (int i = 0; i < m; ++i) {
		int e;
		cin >> e;
		if (e == 1) {
			int l , r , x;
			cin >> l >> r >> x;
		} else {

		}
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