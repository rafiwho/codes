#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100005;
const int LOG = 17;
int a[MAX_N];
int m[MAX_N][LOG]; // m[i][j] is minimum among a[i..i+2^j-1]


int query(int L, int R) { // O(1)
	int length = R - L + 1;
	int k = __bit_width(length) - 1;
	return min(m[L][k], m[R - (1 << k) + 1][k]);
}

int main() {
	// 1) read input
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		m[i][0] = a[i];
	}
	// 2) preprocessing, O(N*log(N))
	for (int k = 1; k < LOG; k++) {
		for (int i = 0; i + (1 << k) - 1 < n; i++) {
			m[i][k] = min(m[i][k - 1], m[i + (1 << (k - 1))][k - 1]);
		}
	}
	// 3) answer queries
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int L, R;
		cin >> L >> R;
		cout << query(L, R) << "\n";
	}
}