#include <iostream>
#include <numeric>

using namespace std;

void solve() {
	static constexpr long long mod{1000000007};

	long long n;
	cin >> n;

	long long ans{0}, d{1};
	for (long long i{2}; d <= n; ++i) {
		auto nd{lcm(d, i)};
		ans = (ans + (n / d - n / nd) * i) % mod;

		d = nd;
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
