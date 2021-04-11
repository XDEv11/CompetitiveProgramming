#include <iostream>
#include <vector>
#include <string>
#include <array>

using namespace std;

constexpr long long mod{1000000007};
static inline long long& mod_(long long& x) {
	return x %= mod;
}

constexpr int MAX{200000};
vector<long long> T(MAX + 1);

static void build_T() {
	T[0] = 1;
	array<long long, 10> cnt{}; cnt[9] = 1;
	for (int i{1}; i <= MAX; ++i) {
		array<long long, 10> nxt{};
		for (int d{0}; d <= 8; ++d) nxt[d + 1] = cnt[d];
		nxt[0] += cnt[9], nxt[1] += cnt[9];

		for (int d{0}; d <= 9; ++d) mod_(cnt[d] = nxt[d]);

		for (int d{0}; d <= 9; ++d) mod_(T[i] += cnt[d]);
	}
}

void solve() {
	string n;
	int m;
	cin >> n >> m;

	array<long long, 10> cnt{};
	for (auto& d : n) ++cnt[d - '0'];

	long long ans{0};
	for (int d{0}; d <= 9; ++d)
		mod_(ans += cnt[d] * T[max(0, m - (9 - d))]);

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	build_T();

	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
