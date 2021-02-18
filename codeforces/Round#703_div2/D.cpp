#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	auto check = [&](int m) mutable {
		vector<int> ps(n + 1);
		ps[0] = 0;
		for (int i{0}; i < n; ++i) ps[i + 1] = (v[i] >= m ? 1 : -1);
		for (int i{1}; i <= n; ++i) ps[i] += ps[i - 1];

		int mn{0};
		for (int i{k}; i <= n; ++i) {
			mn = min(mn, ps[i - k]);
			if (ps[i] - mn > 0) return true;
		}
		return false;
	};

	int l{1}, r{n + 1}; // [l:r)
	while (r - l > 1) {
		int m{(l + r) / 2};
		if (check(m)) l = m;
		else r = m;
	}
	cout << l << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
