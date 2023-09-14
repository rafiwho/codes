#include "iostream"
#include "vector"
#include "map"
using namespace std;

#define pb push_back
#define ff first
#define ss second

const int N = 110;
std::vector<int> g[N];
bool vis[N];
map<int , pair<int, int>>mp;
int t = 1;

inline void dfs(int vertex) {
	if (vis[vertex])
		return ;
	mp[vertex].ff = t;
	t++;
	vis[vertex] = true;
	for (int child : g[vertex]) {
		dfs(child);
	}
	mp[vertex].ss = t;
	t++;
}

void tcase() {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int x , m;
		cin >> x >> m;
		for (int i = 0; i < m; ++i) {
			int a;
			cin >> a;
			g[x].pb(a);
		}
	}

	for (int i = 1; i <= n; ++i) {
		if (!vis[i])
			dfs(i);
	}

	for (auto a : mp) {
		cout << a.ff << ' ' << a.ss.ff << ' ' << a.ss.ss << '\n';
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

