#include <iostream>
#include <vector>
#include <functional>

using namespace std;

// segment tree
template<typename T>
class SGT {
    int n;
    vector<T> t;
    inline int left(int tv) { return tv + 1; }
    // [ tv+1 : tv+2*(tm-tl)-1 ) -> left subtree
    inline int right(int tv, int tl, int tm) { return tv + 2 * (tm - tl); }

    // associative function for SGT
    function<T(const T&, const T&)> merge;
    void modify(int p, const T& x, int tv, int tl, int tr) {
        if (tl == tr - 1) t[tv] = x;
        else {
            int tm{(tl + tr) / 2}, lc{left(tv)}, rc{right(tv, tl, tm)};
            if (p < tm) modify(p, x, lc, tl, tm);
            else modify(p, x, rc, tm, tr);
            t[tv] = merge(t[lc], t[rc]);
        }
    }
    T query(int l, int r, int tv, int tl, int tr) {
        if (l == tl && r == tr) return t[tv];
        int tm{(tl + tr) / 2};
        if (r <= tm) return query(l, r, left(tv), tl, tm);
        else if (l >= tm) return query(l, r, right(tv, tl, tm), tm, tr);
        else return merge(query(l, tm, left(tv), tl, tm)
                , query(tm, r, right(tv, tl, tm), tm, tr));
    }
public:
    explicit SGT(int _n, const decltype(merge)& m) : n{_n}, t(2 * n - 1), merge(m) {}
    explicit SGT(int _n, decltype(merge)&& m) : n{_n}, t(2 * n - 1), merge(m) {}
    void modify(int p, const T& x) { modify(p, x, 0, 0, n); };
    T query(int l, int r) { return query(l, r, 0, 0, n); } // [l:r)

	T binary_search_on_tree(T x) { // assume merge is +
		// first position from the end s.t. suffix sum >= x
		if (t[0] < x) return -1;
		int tv{0}, tl{0}, tr{n};
		while (tr - tl > 1) {
			int tm{(tl + tr) / 2};
			if (t[right(tv, tl, tm)] >= x) tv = right(tv, tl, tm), tl = tm;
			else x -= t[right(tv, tl, tm)], tv = left(tv), tr = tm;
		}
		return tl;
	}
};

void solve() {
	int n;
	cin >> n;
	vector<int> inv(n);
	for (auto& x : inv) cin >> x;

	SGT<int> sgt{n, plus{}};
	for (int i{0}; i < n; ++i) sgt.modify(i, 1);

	vector<int> p(n);
	for (int i{n - 1}; i >= 0; --i) {
		p[i] = sgt.binary_search_on_tree(inv[i] + 1);
		sgt.modify(p[i], 0);
	}

	for (auto& x : p) cout << x + 1 << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t{1};
	// cin >> t;
	while (t--) solve();
	
	return 0;
}
