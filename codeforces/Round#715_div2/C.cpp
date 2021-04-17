#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	sort(v.begin(), v.end());
	vector<vector<long long>> dp(n, vector<long long>(n, 2000000000000));
	dp[0][n - 1] = v[n - 1] - v[0];
	for (int i{0}; i < n; ++i)
		for (int j{n - 1}; j >= i; --j) {
			if (i - 1 >= 0) dp[i][j] = min(dp[i][j], dp[i - 1][j] + v[j] - v[i]);
			if (j + 1 < n) dp[i][j] = min(dp[i][j], dp[i][j + 1] + v[j] - v[i]);
		}

	long long ans{numeric_limits<long long>::max()};
	for (int k{0}; k < n; ++k) ans = min(ans, dp[k][k]);
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();

	return 0;
}
