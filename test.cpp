#include <bits/stdc++.h>
using namespace std;

template <typename T>
T POW(T a, T b ) {
	T ans = 1;
	while (b) {
		if (b & 1) {
			ans *= a;
		}
		a *= a;
		b >>= 1;
	}
	return ans;
}

void tcase() {

	int nod = 1, sod = 1, lpf = 1e9 + 7, gpf = 0, npf = 0;
	set<int>dpf;
	auto f = [&](int n)->void{
		int nn = n;
		for (int i = 2; 1LL * i * i <= nn; ++i) {
			int cnt = 0;
			if (nn % i == 0) {
				while (nn % i == 0) {
					cnt++;
					nn /= i;
				}
				lpf = min(lpf, i);
				gpf = max(gpf, i);
				npf += cnt;
				dpf.emplace(i);
			}
			nod *= (cnt + 1);
			sod *= (POW(i, cnt + 1) - 1) / (i - 1);
		}

		if (nn > 1) {
			nod *= 2;
			sod *= nn + 1;
			dpf.emplace(nn);
			npf++;;

			lpf = min(lpf, nn);
			gpf = max(gpf, nn);
		}
	};

	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		f(x);
		cout << lpf << ' ' << gpf << ' ' << dpf.size() << ' ' << npf << ' ' << nod << ' ' << sod << '\n';
		nod = sod = 1; gpf = npf = 0;
		lpf = 1E9; dpf.clear();
	}

}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}