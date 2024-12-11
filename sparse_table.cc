#include <bits/stdc++.h>
using namespace std;

struct sparse_table {
    vector<vector<int>> m;

    void build(const vector<int>& a) {
        int n = a.size();
        int LOG = __bit_width(n);
        m.assign(n, vector<int>(LOG));

        for (int i = 0; i < n; i++) {
            m[i][0] = a[i];
        }
        for (int k = 1; (1 << k) <= n; k++) {
            for (int i = 0; i + (1 << k) - 1 < n; i++) {
                m[i][k] = min(m[i][k - 1], m[i + (1 << (k - 1))][k - 1]);
            }
        }
    }

    int query(int L, int R) {
        int length = R - L + 1;
        int k = __bit_width(length) - 1;
        return min(m[L][k], m[R - (1 << k) + 1][k]);
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    SparseTable st;
    st.build(a);

    for (int i = 0; i < q; i++) {
        int L, R;
        cin >> L >> R;
        cout << st.query(L, R) << "\n";
    }
}
