#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

using namespace std;

void solve() {
	using ll = long long;
	int n;
	ll k;
	cin >> n >> k;

	if (--k >= 1ll << min(60, (n - 1))) return cout << "-1\n"s, []{}();

	vector<int> r(n, false);
	for (int i{0}; i < n - 1; ++i) {
		ll half{1ll << min(60, (n - i - 2))};
		if (k >= half) k -= half, r[i] = true;
	}

	vector<int> p(n); iota(p.begin(), p.end(), 1);
	for (int i{0}; i < n; ++i) {
		int j{i};
		while (r[j]) ++j;
		reverse(p.begin() + i, p.begin() + j + 1);
		i = j;
	}

	for (auto& x : p) cout << x << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
