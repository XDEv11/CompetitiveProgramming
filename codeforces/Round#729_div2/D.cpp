#include <iostream>
#include <vector>

using namespace std;

void solve() {
	static constexpr long long mod{998244353};

	int n;
	cin >> n;
	vector<int> v(n + 1, 0);
	for (int i{1}; i <= n; ++i) {
		char op;
		cin >> op;
		if (op == '+') cin >> v[i];
	}
	
	long long ans{0};
	vector<vector<long long>> dp(2);
	for (int k{1}; k <= n; ++k) {
		if (!v[k]) continue; // -
		dp[0].assign(1, 1);

		for (int i{1}; i <= n; ++i) {
			if (i == k) dp[1].assign(dp[0].size(), 0);
			else dp[1] = dp[0]; // not taken

			if (v[i]) { // + v[i]
				if (v[i] < v[k] || (v[i] == v[k] && i < k)) {
					dp[1].push_back(0);
					for (int j{0}; j < dp[0].size(); ++j) dp[1][j + 1] = (dp[1][j + 1] + dp[0][j]) % mod;
				} else
					for (int j{0}; j < dp[0].size(); ++j) dp[1][j] = (dp[1][j] + dp[0][j]) % mod;
			} else { // -
				for (int j{i < k ? 0 : 1}; j < dp[0].size(); ++j) dp[1][max(j - 1, 0)] = (dp[1][max(j - 1, 0)] + dp[0][j]) % mod;
			}
			swap(dp[0], dp[1]);
		}

		for (auto& x : dp[0]) ans = (ans + v[k] * x) % mod;
	}

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
