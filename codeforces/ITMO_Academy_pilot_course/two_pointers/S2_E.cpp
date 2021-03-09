#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	vector<int> cnt(100001, 0);
	long long ans{0};
	int c{0}, i{0};
	for (int j{0}; j < n; ++j) {
		c += (cnt[v[j]] == 0), ++cnt[v[j]];
		while (c > k) --cnt[v[i]], c -= (cnt[v[i]] == 0), ++i;
		ans += (j - i + 1);
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
