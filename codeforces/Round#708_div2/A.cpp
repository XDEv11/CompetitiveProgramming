#include <iostream>
#include <array>

using namespace std;

void solve() {
	int n;
	cin >> n;
	array<int, 101> cnt{};
	for (int i{0}; i < n; ++i) {
		int x;
		cin >> x;
		++cnt[x];
	}

	for (int i{0}; i <= 100; ++i)
		if (cnt[i]) cout << i << ' ';
	for (int i{0}; i <= 100; ++i)
		while (--cnt[i] > 0) cout << i << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
