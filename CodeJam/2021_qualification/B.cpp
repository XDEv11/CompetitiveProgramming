#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

void solve() {
	static int t{0};
	cout << "Case #" << ++t << ": ";

	int x, y;
	string s{};
	cin >> x >> y >> s;

	vector<array<int, 2>> dp(s.size(), {100000, 100000});
	if (s[0] != 'J') dp[0][0] = 0;
	if (s[0] != 'C') dp[0][1] = 0;
	for (int i{1}; i < s.size(); ++i) {
		if (s[i] != 'C') // JJ or CJ
			dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + x);
		if (s[i] != 'J') // CC or JC
			dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + y);
	}

	cout << min(dp.back()[0], dp.back()[1]) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
