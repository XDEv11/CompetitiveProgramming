#include <iostream>
#include <vector>
#include <utility>

using namespace std;

using ll = long long;

void solve() {
	static int t{0};
	cout << "Case #" << ++t << ": ";

	int m;
	cin >> m;
	vector<pair<ll, ll>> pri(m);
	ll all{0};
	for (auto& [p, n] : pri) {
		cin >> p >> n;
		all += p * n;
	}

	static constexpr ll ub{3025};
	for (long long x{0}; x <= all && x <= ub; ++x) {
		ll ans{all - x}, s{ans}, y{0};
		for (auto& [p, n] : pri) {
			for (int i{0}; i < n; ++i)
				if (s % p == 0) s /= p, y += p;
				else break;
		}
		if (s != 1 || x != y) continue;
		return cout << ans << '\n', []{}();
	}
	cout << "0\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
