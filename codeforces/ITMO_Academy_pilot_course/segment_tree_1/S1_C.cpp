#include <iostream>
#include <vector>
#include <functional>
#include <limits>

using namespace std;

// segment tree
template<typename T>
class SGT {
	int n;
	vector<T> t; // root starts at 1
	// associative function for SGT
	function<T(const T&, const T&)> merge;
public:
	explicit SGT(int _n, const decltype(merge)& m) : n{_n}, t(2 * n), merge(m) {}
	explicit SGT(int _n, decltype(merge)&& m) : n{_n}, t(2 * n), merge(m) {}
	void modify(int p, const T& x) {
		for (t[p += n] = x; p > 1; p >>= 1) t[p >> 1] = merge(t[p], t[p ^ 1]);
	}
	T query(int l, int r, T init) { // [l:r)
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

	struct data_t {int mn, cnt;};

	SGT<data_t> sgt{
		n,
		[](const data_t& x, const data_t& y) -> data_t {
			if (x.mn == y.mn) return {x.mn, x.cnt + y.cnt};
			else if (x.mn < y.mn) return x;
			else return y;
		}
	};

	for (int i{0}; i < n; ++i) {
		int x;
		cin >> x;
		sgt.modify(i, {x, 1});
	}

	while (m--) {
		int op, var1, var2;
		cin >> op >> var1 >> var2;
		if (op == 1) sgt.modify(var1, {var2, 1});
		else if (op == 2) {
			auto res{sgt.query(var1, var2, {numeric_limits<int>::max(), 0})};
			cout << res.mn << ' ' << res.cnt << '\n';
		}
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
