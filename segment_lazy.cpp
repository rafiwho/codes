#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct RMQ {
	vector<T>v, t;
	size_t size = 0;

	RMQ(const vector<T>&vv) {
		v = vv;
		size = T(vv.size());
		t.assign(size << 2 , 0);
		if (!vv.empty())
			build(1, 1, size);
	}
	T mrge(T a, T b) {
		return a & b;
	}
	void build(T N , T s, T e) {
		if (s == e) {
			t[N] = v[s];
			return;
		}
		T mid = (s + e) >> 1;
		build(N << 1, s, mid);
		build(N << 1 | 1, mid + 1, e);
		t[N] = mrge(t[N << 1], t[N << 1 | 1]);
	}
	T query(T l, T r) {
		return query(1, 1, size, l, r);
	}
	T query(T N , T s, T e, T l, T r) {
		if (s > r || e < l) {
			return T((1 << 30) - 1);
		}
		if (s >= l && e <= r) {
			return t[N];
		}
		T mid = (s + e) >> 1;
		T q1 = query(N << 1, s, mid, l, r);
		T q2 = query(N << 1 | 1, mid + 1, e, l, r);
		return mrge(q1, q2);
	}
	void update(T i, T V) {
		update(1, 1, size, i, V);
	}
	void update(T N , T s, T e, T i, T V) {
		if (s == e) {
			t[N] = V;
			return;
		}
		T mid = (s + e) >> 1;
		if (i <= mid) {
			update(N << 1, s, mid, i, V);
		} else {
			update(N << 1 | 1, mid + 1, e, i, V);
		}
		t[N] = mrge(t[N << 1], t[N << 1 | 1]);
	}
};
void tcase() {

}
int32_t main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   int t = 1;
   //cin >> t;

   while (t-- > 0)
     tcase();
}