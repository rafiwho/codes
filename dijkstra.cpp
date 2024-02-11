#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
constexpr i64 INF = 1E15;
constexpr int N = 2E5+5;
std::vector<array<int,2>> v[N];
void tcase() {
	int n; cin >> n;
	for (int i = 1; i <= n-1; ++i) {
		int a,b,x; cin >> a >> b >> x;
		v[i].push_back({i+1,a});
		v[i].push_back({x,b});
	}
	auto dijkstra = [&](int source)->i64{
		min_heap<array<i64,2>>q;
		vector<bool>vis(N,false);
		vector<i64>dis(N,INF);
		q.push({0,source});
		dis[source] = 0;
		while(!q.empty()){
			auto [cur_w,cur_v] = q.top();
			q.pop(); if(vis[cur_v])continue;
			vis[cur_v] = true;
			for(auto [c_v,c_w]:v[cur_v]){
				if(dis[cur_v] + c_w < dis[c_v]){
					dis[c_v] = dis[cur_v] + c_w;
					q.push({dis[c_v],c_v}); 
				}
			}
		}
		return dis[n];
	};
	cout << dijkstra(1) << '\n';
}
int32_t main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   int t = 1;
   //cin >> t;

   while (t-- > 0)
     tcase();
}