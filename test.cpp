#include <bits/stdc++.h>
using namespace std;
vector<int>get_div(int n) {
    vector<int>divs;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divs.push_back(i);
            divs.push_back(n / i);
        }
    }
    sort(divs.begin(), divs.end());
    divs.erase(unique(divs.begin(), divs.end()), divs.end());
    return divs;
}
#include "test.h"
void tcase() {
    int n;
    cin >> n;
    cout << (get_div(n).size() & 1 ? "FastestFinger\n" : "Ashishgup\n");

}
int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int32_t t = 1;
    cin >> t;

    while (t-- > 0)
        tcase();
}