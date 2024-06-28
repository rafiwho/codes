template <typename T>
class SegmentTree {
private:
	vector<T> tree;
	int size;

	T merge(T a, T b) {
		return a + b; // For sum
	}

	void build(const vector<T>& arr, int v, int tl, int tr) {
		if (tl == tr) {
			tree[v] = arr[tl];
		} else {
			int tm = (tl + tr) / 2;
			build(arr, v << 1, tl, tm);
			build(arr, v << 1 | 1, tm + 1, tr);
			tree[v] = merge(tree[v << 1], tree[v << 1 | 1]);
		}
	}

	T query(int v, int tl, int tr, int l, int r) {
		if (l > r)
			return 0; // or appropriate value
		if (l == tl && r == tr)
			return tree[v];
		int tm = (tl + tr) / 2;
		return merge(query(v << 1, tl, tm, l, min(r, tm)),
		             query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r));
	}

	void update(int v, int tl, int tr, int pos, T newVal) {
		if (tl == tr) {
			tree[v] = newVal;
		} else {
			int tm = (tl + tr) / 2;
			if (pos <= tm)
				update(v << 1, tl, tm, pos, newVal);
			else
				update(v << 1 | 1, tm + 1, tr, pos, newVal);
			tree[v] = merge(tree[v << 1], tree[v << 1 | 1]);
		}
	}

public:
	SegmentTree(const vector<T>& arr) {
		size = arr.size();
		tree.assign(size << 2, 0); // adjust size as needed
		build(arr, 1, 0, size - 1);
	}

	T query(int l, int r) {
		return query(1, 0, size - 1, l, r);
	}

	void update(int pos, T newVal) {
		update(1, 0, size - 1, pos, newVal);
	}
};