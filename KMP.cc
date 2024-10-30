#include <bits/stdc++.h>
using namespace std;
vector<int>getLPS(const string pattern) {
	int n = int(pattern.size());
	vector<int>lps(n, 0);
	int i = 1;
	int j = 0;
	while (i < n) {
		if (pattern[i] == pattern[j]) {
			lps[i++] = j + 1; j++;
		} else {
			if (j != 0) {
				j = lps[j - 1];
			} else {
				lps[i] = 0;
				i++;
			}
		}
	}
	return lps;
}
bool KMP(const string text, const string pattern) {
	int t_len = int(text.size());
	int pat_len = int(pattern.size());
	int i = 0 , j = 0 ;
	vector<int>lps = getLPS(pattern);
	while (i < t_len && j < pat_len) {
		if (text[i] == pattern[j]) {
			i++, j++;
		} else {
			if (j != 0) {
				j = lps[j - 1];
			} else {
				i++;
			}
		}
	}
	return j == pat_len;
}

void tcase() {
	string s, p; cin >> s >> p;
	cout << KMP(s, p) << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}
