#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	long long s;
	cin >> n >> s;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	int ans{0};
	long long c{0};

	int i{0};
	for (int j{0}; j < n; ++j) {
		c += v[j];
		while (c > s) c -= v[i++];
		ans = max(ans, j - i + 1);
	}
	
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
