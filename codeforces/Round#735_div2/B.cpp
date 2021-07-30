#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	long long ans{numeric_limits<long long>::min()};
	for (int j{n - 1}; j >= 0; --j) {
		if (j * (j + 1ll) <= ans) break;
		for (int i{j - 1}; i >= 0; --i) {
			if ((i + 1ll) * (j + 1) <= ans) break;
			ans = max(ans, (i + 1ll) * (j + 1) - k * (v[i] | v[j]));
		}
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
