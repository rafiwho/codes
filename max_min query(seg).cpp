#include <bits/stdc++.h>
using namespace std;

const int MAXN = int(2e5) + 10;
const int INF = int(2e9) + 7;

struct Node {
    int val, count, index;

    Node() : val(INF), count(0), index(-1) {}

    Node(int v, int c, int i) : val(v), count(c), index(i) {}
};

Node min_tree[4 * MAXN];
Node max_tree[4 * MAXN];
vector<int> v;

Node ck_mn(Node& a, Node& b) {
    if (a.val < b.val)
        return a;
    if (a.val > b.val)
        return b;
    return Node(a.val, a.count + b.count, a.index);
}
Node ck_mx(Node& a, Node& b) {
    if (a.val < b.val)
        return b;
    if (a.val > b.val)
        return a;
    return Node(a.val, a.count + b.count, a.index);
}

void build(int node, int st, int en) {
    if (st == en) {
        min_tree[node] = {v[st], 1, st};
        max_tree[node] = {v[st], 1, st};
    } else {
        int mid = (st + en) >> 1;
        build(node << 1, st, mid);
        build((node << 1) + 1, mid + 1, en);
        min_tree[node] = ck_mn(min_tree[node << 1], min_tree[(node << 1) + 1]);
        max_tree[node] = ck_mx(max_tree[node << 1], max_tree[(node << 1) + 1]);
    }
}


Node query_min(int node, int st, int en, int l, int r) {
    if (st > r || en < l) {
        return {INF, 0, -1};
    }
    if (st >= l && en <= r) {
        return min_tree[node];
    }
    int mid = (st + en) >> 1;
    Node q1 = query_min(node << 1, st, mid, l, r);
    Node q2 = query_min((node << 1) + 1, mid + 1, en, l, r);
    return ck_mn(q1, q2);
}

Node query_max(int node, int st, int en, int l, int r) {
    if (st > r || en < l) {
        return {-INF, 0, -1};
    }
    if (st >= l && en <= r) {
        return max_tree[node];
    }
    int mid = (st + en) >> 1;
    Node q1 = query_max(node << 1, st, mid, l, r);
    Node q2 = query_max((node << 1) + 1, mid + 1, en, l, r);
    return ck_mx(q1, q2);
}

void tcase() {
    int N;
    cin >> N;
    v.assign(N+1,0);
    for (int i = 1; i <= N; ++i) {
    	cin >> v[i];
    }
    build(1, 1, N);
    int M; cin >> M;
    while (M--) {
      int l, r;
      cin >> l >> r;
      Node min_result = query_min(1, 1, N, l, r);
      Node max_result = query_max(1, 1, N, l, r);
      if(max_result.val == min_result.val){
      	cout << -1 << ' '<< -1 << '\n';
      }else{
      	cout << max_result.index << ' '<< min_result.index << '\n';
      }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t-- > 0)
        tcase();
}
