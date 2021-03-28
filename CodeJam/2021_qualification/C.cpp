#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void solve() {
	static int t{0};
	cout << "Case #" << ++t << ": ";

	int n, c;
	cin >> n >> c;
	vector<int> v(n); iota(v.begin(), v.end(), 1);

	if (c > (n - 1) * (2 + n) / 2 || c < n - 1) return cout << "IMPOSSIBLE\n", []{}();
	c -= (n - 1);

	for (int i{n - 2}; i >= 0 && c; --i) {
		int len{min(c, n - i - 1)};
		reverse(v.begin() + i, v.begin() + i + len + 1);
		c -= len;
	}

	for (auto& x : v) cout << x << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
