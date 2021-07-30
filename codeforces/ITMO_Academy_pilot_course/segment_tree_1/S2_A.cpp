#include <iostream>
#include <vector>

using namespace std;

template<typename value_t, class merge_t>
class SGT {
    int n;
    vector<value_t> t; // root starts at 1
    merge_t merge; // associative function for SGT
public:
    explicit SGT(int _n = 0, const merge_t& _merge = merge_t{})
        : n{_n}, t(2 * n), merge{_merge} {}
    void modify(int p, const value_t& x) {
        for (t[p += n] = x; p > 1; p >>= 1)
			if (p & 1) t[p >> 1] = merge(t[p - 1], t[p]);
			else t[p >> 1] = merge(t[p], t[p + 1]);
    }
    value_t query(int l, int r, value_t init) { // [l:r)
		value_t L{init}, R{init};
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) L = merge(L, t[l++]);
            if (r & 1) R = merge(t[--r], R);
        }
        return merge(L, R);
    }
};

void solve() {
	int n, m;
	cin >> n >> m;

	struct value_t {
		long long sum, pre, suf, mx;
		value_t()=default;
		value_t(long long x) : sum{x}, pre{x}, suf{x}, mx{x} {}
	};
	struct merge_t {
		value_t operator()(const value_t& x, const value_t& y) {
			value_t res{};
			res.sum = x.sum + y.sum;
			res.pre = max(x.pre, x.sum + y.pre);
			res.suf = max(x.suf + y.sum, y.suf);
			res.mx = max(max(x.mx, y.mx), x.suf + y.pre);
			return res;
		}
	};

	SGT<value_t, merge_t> sgt{n};
	for (int i{0}; i < n; ++i) {
		long long x;
		cin >> x;
		sgt.modify(i, x);
	}
	
	cout << sgt.query(0, n, 0).mx << '\n';
	while (m--) {
		int i; long long x;
		cin >> i >> x;
		sgt.modify(i, x);
		cout << sgt.query(0, n, 0).mx << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t{1};
	// cin >> t;
	while (t--) solve();
	
	return 0;
}
