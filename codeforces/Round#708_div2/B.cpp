#include <iostream>
#include <array>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	array<int, 100000> cnt{};
	for (int i{0}; i < n; ++i) {
		int x;
		cin >> x;
		++cnt[x % m];
	}

	int ans{0};
	if (cnt[0]) ans += 1;
	for (int i{1}; i <= m / 2; ++i) {
		if (cnt[i] || cnt[m - i]) ans += 1;
		if (cnt[i] > cnt[m - i] + 1) ans += cnt[i] - (cnt[m - i] + 1);
		if (cnt[m - i] > cnt[i] + 1) ans += cnt[m - i] - (cnt[i] + 1);
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
