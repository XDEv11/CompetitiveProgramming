#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve() {
	auto mod_ = [](long long& x) {
		constexpr long long mod{1000000007};
		x = ((x % mod) + mod) % mod;
	};

	int n;
	cin >> n;
	vector<long long> b(n);
	for (auto& x : b) cin >> x;

	map<long long, long long> mp{}; // for j in [0:i] {a[i] - b[i]}, dp
	mp.emplace(0, 1);
	long long tot{1}, x{0};
	for (int i{0}; i < n; ++i) {
		long long coin{mp[x]};
		mp[x] = tot;
		x -= b[i];
		tot = 2 * tot - coin, mod_(tot);
	}

	cout << tot << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
