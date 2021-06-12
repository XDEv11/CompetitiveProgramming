#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	int all{0};
	for (int i{0}; i < n; ++i) all ^= v[i];

	int a{0}, b{all};
	for (int i{0}; i < n - 1; ++i) {
		a ^= v[i], b ^= v[i];
		if (a == b) return cout << "YES\n"s, []{}();
	}

	int x{0}, cnt{0};
	for (int i{0}; i < n; ++i) {
		x ^= v[i];
		if (x == all) ++cnt, x = 0;
	}

	cout << (!x && cnt >= 2 ? "YES"s : "NO"s) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
