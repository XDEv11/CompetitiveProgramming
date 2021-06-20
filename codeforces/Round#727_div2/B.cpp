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
	explicit SGT(int _n, const merge_t& m = merge_t{}) : n{_n}, t(2 * n), merge{m} {}
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
	int n, q;
	cin >> n >> q;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	SGT<int, plus<int>> sgt{n};
	for (int i{0}; i < n; ++i)
		sgt.modify(i, v[i] - 'a' + 1);

	while (q--) {
		int l, r;
		cin >> l >> r, --l;
		cout << sgt.query(l, r, 0) << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();

	return 0;
}
