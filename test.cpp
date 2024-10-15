#include <bits/stdc++.h>
using namespace std;

vector<int> z_function(const string &s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}
int mrge(string &a, string &b) {
    string con = b + "$" + a;
    vector<int> z = z_function(con);
    int mx = 0;
    for (int i = b.size() + 1; i < z.size(); ++i) {
        if (z[i] == con.size() - i) {
            mx = z[i];
            break;
        }
    }
    return mx;
}

template <typename T>
void ckmax(T &a, T b) {
    a = a > b ? a : b;
}

int n;
const int N = 11;
vector<vector<int>> gain(N, vector<int>(N, 0));
vector<vector<int>> dp(N, vector<int>(1 << N, -1));

int f(int i, int mask) {
    if (__builtin_popcount(mask) == n) return 0;
    int &ans = dp[i][mask];
    if (ans != -1) return ans;
    ans = 0;
    for (int k = 0; k < n; ++k) {
        if (!(mask & (1 << k))) {
            ans = max(ans, gain[i][k] + f(k, mask | (1 << k)));
        }
    }
    return ans;
}
void tcase() {
    cin >> n;
    vector<string> v(n);
    int ans = 0;
    int emnie = 0;
    for (auto &s : v) {
        cin >> s;
        ans += s.size();
    }
    sort(v.begin(), v.end(), [](auto & a, auto & b) { return a.size() > b.size(); });

    vector<bool> bad(n, false);
    for (int i = 0; i < n; ++i) {
        if (!bad[i]) {
            for (int j = i + 1; j < n; ++j) {
                if (!bad[j] && mrge(v[i], v[j]) == v[j].size()) {
                    bad[j] = true;
                    emnie += v[j].size();
                }
            }
        }
    }

    vector<string> nv;
    for (int i = 0; i < n; ++i) {
        if (!bad[i]) {
            nv.push_back(v[i]);
        }
    }
    swap(nv, v);
    n = v.size();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                gain[i][j] = mrge(v[i], v[j]);
            }
        }
    }
    int best = 0;
    for (int i = 0; i < n; ++i) {
        ckmax(best, f(i, 1 << i));
    }
    cout << ans - (best + emnie) << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        tcase();
    }
}
