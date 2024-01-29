#include <bits/stdc++.h>
using namespace std;

void tcase() {
	int n , k , m; cin >> n >> k >> m;
	string s; cin >> s;
	map<char, int> fre;
	
	for(char ch:s){
		fre[ch]++;
	}

	for(auto [x,y]: fre){
		if(y < n){
			cout << "NO\n";
			cout << string(n,x) << '\n';
			return ;
		}
	}

	cout  << "YES\n";	
	
}
int32_t main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   int t = 1;
   cin >> t;

   while (t-- > 0)
     tcase();
}