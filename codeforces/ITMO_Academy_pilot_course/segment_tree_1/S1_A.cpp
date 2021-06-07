#include <iostream>
#include <vector>
#include <functional>

using namespace std;

// segment tree
template<typename type, class merge_t>
class SGT {
	int n;
	vector<type> t; // root starts at 1
	merge_t merge; // associative function for SGT 
public:
	explicit SGT(int _n, const merge_t& _merge = merge_t{}) : n{_n}, t(2 * n), merge{_merge} {}
	void modify(int p, const type& x) {
		for (t[p += n] = x; p > 1; p >>= 1) t[p >> 1] = merge(t[p], t[p ^ 1]);
	}
	type query(int l, int r, type init) { // [l:r)
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l & 1) init = merge(init, t[l++]);
			if (r & 1) init = merge(init, t[--r]);
		}
		return init;
	}
};

void solve() {
	int n, m;
	cin >> n >> m;

	SGT<long long, plus<long long>> sgt{n};
	for (int i{0}; i < n; ++i) {
		long long x;
		cin >> x;
		sgt.modify(i, x);
	}

	while (m--) {
		int op, var1, var2;
		cin >> op >> var1 >> var2;
		if (op == 1) sgt.modify(var1, var2);
		else if (op == 2) cout << sgt.query(var1, var2, 0) << '\n';
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
