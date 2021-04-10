#include <iostream>
#include <vector>
#include <functional>

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
	T query(int l, int r) { // [l:r)
		T res{};
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l & 1) res = merge(res, t[l++]);
			if (r & 1) res = merge(res, t[--r]);
		}
		return res;
	}
};

void solve() {
	int n, m;
	cin >> n >> m;

	SGT<long long> sgt{n, plus{}};
	for (int i{0}; i < n; ++i) {
		long long x;
		cin >> x;
		sgt.modify(i, x);
	}

	while (m--) {
		int op, var1, var2;
		cin >> op >> var1 >> var2;
		if (op == 1) sgt.modify(var1, var2);
		else if (op == 2) cout << sgt.query(var1, var2) << '\n';
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
