#include <bits/stdc++.h>
using namespace std;

void tcase() {
	string s;
	cin >> s;
	size_t sz = s.size();
	set<char>st(s.begin(), s.end());
	if (st.size() == 1) {
		cout << 0 << '\n';
		return ;
	}
	if (sz == 4 && s[1] == s[2]) {
		cout << 1 << '\n';
		return;
	}
	map<char, int>mp;
	for (auto &S : s)
		mp[S]++;
	int mx_fre = 0;
	char ch;
	for (auto [x, y] : mp) {
		if (y > mx_fre) {
			mx_fre = y;
			ch = x;
		}
	}
	vector<int>posi;
	for (auto i = 0; i < sz; ++i)		{
		if (s[i] == ch)
			posi.push_back(i);
	}
	int odd = 0;
	int even = 0;
	for (auto i = 0; i < posi.size(); ++i)		{
		if (posi[i] & 1)
			odd++;
		else
			even++;
	}
	bool all_same = true;
	for (auto i = odd > even ? 1 : 0; i < sz; i += 2)		{
		all_same &= s[i] == ch;
	}
	if (all_same) {
		cout << 1 << '\n';
		return;
	}
	if (odd == even) {
		all_same = true;
		for (auto i = 0; i < sz; i += 2)		{
			all_same &= s[i] == ch;
		}
		if (all_same) {
			cout << 1 << '\n';
			return;
		}
		all_same = true;
		for (auto i = 1; i < sz; i += 2)		{
			all_same &= s[i] == ch;
		}
		if (all_same) {
			cout << 1 << '\n';
			return;
		}
	}
	cout << int(__lg(sz)) << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	cin >> t;

	while (t-- > 0)
		tcase();
}