#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

constexpr long long mod{1000000007};
static inline long long& mod_(long long& x) {
	return x %= mod;
}

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	array<int, 30> cnt{};
	for (auto& x : v)
		for (int b{0}; b <= 29; ++b)
			if (x & (1 << b)) ++cnt[b];

	for (auto& x : v)
		for (int b{0}; b <= 29; ++b)
			if (cnt[b] == n) x &= ~(1 << b);

	long long zc{count(v.begin(), v.end(), 0)}; // zero count

	long long ans{zc * (zc - 1)};
	for (long long i{n - 2}; i >= 1; --i) mod_(ans *= i);

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
