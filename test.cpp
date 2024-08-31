#include <bits/stdc++.h>
using namespace std;

const int64_t N = int64_t(2e5) + 10;
const int64_t INF = int64_t(1E18) + 7;

struct Node {
    int64_t val, count, index;

    Node() : val(INF), count(0), index(-1) {}

    Node(int64_t v, int64_t c, int64_t i) : val(v), count(c), index(i) {}
};

Node min_tree[4 * N], max_tree[4 * N];
int64_t lazy[4 * N];
vector<int64_t> v;

Node ck_mn(const Node& a, const Node& b) {
    if (a.val < b.val)
        return a;
    if (a.val > b.val)
        return b;
    return Node(a.val, a.count + b.count, a.index);
}

Node ck_mx(const Node& a, const Node& b) {
    if (a.val < b.val)
        return b;
    if (a.val > b.val)
        return a;
    return Node(a.val, a.count + b.count, a.index);
}

void propagate(int64_t node, int64_t st, int64_t en) {
    if (lazy[node] != 0) {
        min_tree[node].val += lazy[node];
        max_tree[node].val += lazy[node];
        if (st != en) {
            lazy[node << 1] += lazy[node];
            lazy[(node << 1) + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void build(int64_t node, int64_t st, int64_t en) {
    if (st == en) {
        min_tree[node] = {v[st], 1, st};
        max_tree[node] = {v[st], 1, st};
    } else {
        int64_t mid = (st + en) >> 1;
        build(node << 1, st, mid);
        build((node << 1) + 1, mid + 1, en);
        min_tree[node] = ck_mn(min_tree[node << 1], min_tree[(node << 1) + 1]);
        max_tree[node] = ck_mx(max_tree[node << 1], max_tree[(node << 1) + 1]);
    }
}

void update(int64_t node, int64_t st, int64_t en, int64_t l, int64_t r, int64_t val) {
    propagate(node, st, en);
    if (st > r || en < l) return;
    if (st >= l && en <= r) {
        lazy[node] += val;
        propagate(node, st, en);
        return;
    }
    int64_t mid = (st + en) >> 1;
    update(node << 1, st, mid, l, r, val);
    update((node << 1) + 1, mid + 1, en, l, r, val);
    min_tree[node] = ck_mn(min_tree[node << 1], min_tree[(node << 1) + 1]);
    max_tree[node] = ck_mx(max_tree[node << 1], max_tree[(node << 1) + 1]);
}

Node query_min(int64_t node, int64_t st, int64_t en, int64_t l, int64_t r) {
    propagate(node, st, en);
    if (st > r || en < l) {
        return {INF, 0, -1};
    }
    if (st >= l && en <= r) {
        return min_tree[node];
    }
    int64_t mid = (st + en) >> 1;
    Node q1 = query_min(node << 1, st, mid, l, r);
    Node q2 = query_min((node << 1) + 1, mid + 1, en, l, r);
    return ck_mn(q1, q2);
}

Node query_max(int64_t node, int64_t st, int64_t en, int64_t l, int64_t r) {
    propagate(node, st, en);
    if (st > r || en < l) {
        return { -INF, 0, -1};
    }
    if (st >= l && en <= r) {
        return max_tree[node];
    }
    int64_t mid = (st + en) >> 1;
    Node q1 = query_max(node << 1, st, mid, l, r);
    Node q2 = query_max((node << 1) + 1, mid + 1, en, l, r);
    return ck_mx(q1, q2);
}

void tcase() {
    int64_t n, q;
    cin >> n >> q;
    v.assign(n + 1, 0);
    build(1, 1, n);
    while (q--) {
        int64_t type, l, r;
        cin >> type >> l >> r;
        if (type == 1) {
            if (l == r) {
                cout << 1 << '\n';
            } else {
                int64_t mx = query_max(1, 1, n, l + 1, r).val;
                int64_t mn = query_min(1, 1, n, l + 1, r).val;
                if (mx == 0 && mn == 0) {
                    cout << 1 << '\n';
                } else {
                    cout << 0 << '\n';
                }
            }
        } else {
            int64_t a, b;
            cin >> a >> b;
            update(1, 1, n, l, l, a);
            if (l + 1 <= r)
                update(1, 1, n, l + 1, r, b);
            if (r + 1 <= n)
                update(1, 1, n, r + 1, r + 1, -(a + b * (r - l)));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;

    while (t-- > 0)
        tcase();
}
