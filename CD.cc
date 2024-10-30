#include <bits/stdc++.h>
using namespace std;

void tcase() {
    int sum, n;
    while (cin >> sum >> n) {
        int arr[n];
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        vector<int> ans;
        long long prev = 1E15;
        function<void(int, long long, vector<int>&)> BT = [&](int i, long long cur, vector<int>& temp) -> void {
            if (i == n) {
                if (abs(cur - sum) < prev && cur <= sum) {
                    ans = temp;
                    prev = abs(cur - sum);
                }
                return;
            }
            temp.emplace_back(arr[i]);
            BT(i + 1, cur + arr[i], temp);
            temp.pop_back();
            BT(i + 1, cur, temp);
        };
        vector<int> temp;
        BT(0, 0, temp);
        for (int x : ans)
            cout << x << ' ';
        cout << "sum:" << accumulate(ans.begin(), ans.end(), INT64_C(0)) << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;

    while (t-- > 0)
        tcase();

    return 0;
}
