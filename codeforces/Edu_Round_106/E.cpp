#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

void solve() {
	static constexpr long long m{998244353};

	string a, b;
	cin >> a >> b;
	int an{a.size()}, bn{b.size()};
	a = ' ' + a;
	b = ' ' + b;

	long long ans{0};

	vector<vector<array<long long, 2>>> dp(an + 1, vector<array<long long, 2>>(bn + 1, {0, 0}));
	for (int i{0}; i <= an; ++i)
		for (int j{0}; j <= bn; ++j) {
			if (i) dp[i][j][0] = 1;
			if (j) dp[i][j][1] = 1;

			if (i - 1 >= 0) {
				if (a[i - 1] != a[i]) dp[i][j][0] += dp[i - 1][j][0];
				if (b[j] != a[i]) dp[i][j][0] += dp[i - 1][j][1];
			}
			if (j - 1 >= 0) {
				if (a[i] != b[j]) dp[i][j][1] += dp[i][j - 1][0];
				if (b[j - 1] != b[j]) dp[i][j][1] += dp[i][j - 1][1];
			}

			dp[i][j][0] %= m, dp[i][j][1] %= m;
			ans += dp[i][j][0] + dp[i][j][1], ans %= m;
		}

	for (int i{1}; i <= an; ++i) {
		int k{i};
		while (k + 1 <= an && a[k] != a[k + 1]) ++k;
		int len{k - i + 1};
		ans -= len * (len + 1) / 2 * (bn + 1), ans %= m;
		i = k;
	}
	for (int j{1}; j <= bn; ++j) {
		int k{j};
		while (k + 1 <= bn && b[k] != b[k + 1]) ++k;
		int len{k - j + 1};
		ans -= len * (len + 1) / 2 * (an + 1), ans %= m;
		j = k;
	} 

	ans = (ans + m) % m;
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
