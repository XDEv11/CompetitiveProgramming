#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	static int t{0};
	cout << "Case #" << ++t << ": ";

	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	int ans{0};
	for (int i{0}; i < n - 1; ++i) {
		int mn{n + 1}, j;
		for (int k{i}; k < n; ++k)
			if (v[k] < mn) mn = v[k], j = k;
		reverse(v.begin() + i, v.begin() + j + 1);
		ans += j - i + 1;
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
