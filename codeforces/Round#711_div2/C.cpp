#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	auto mod_ = [](long long& x) {return x %= 1000000007;};

	int n, k;
	cin >> n >> k;

	vector<vector<long long>> dp(k + 1, vector<long long>(n + 1));
	fill(dp[0].begin(), dp[0].end(), 0);
	fill(dp[1].begin(), dp[1].end(), 1);

	for (int i{2}; i <= k; ++i) {
		vector<long long> ps(n);
		ps[0] = 0;
		for (int j{1}; j < n; ++j) mod_(ps[j] = ps[j - 1] + dp[i - 2][j]);

		dp[i][n] = 1;
		for (int j{n - 1}; j >= 0; --j) {
			mod_(dp[i][j] = dp[i][j + 1] + 1 + ps[j]);
		}
	}

	cout << dp[k][0] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
