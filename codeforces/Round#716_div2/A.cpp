#include <iostream>
#include <vector>
#include <string>

using namespace std;

static unsigned long long Intsqrt(unsigned long long x) {
	unsigned long long l{0ULL}, r{1ULL << 32};
	while (r - l > 1) {
		auto m{(l + r) / 2};
		if (m * m <= x) l = m;
		else r = m;
	}
	return l;
}

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	bool ans{false};
	for (auto& x : v) {
		int r{Intsqrt(x)};
		if (r * r != x) ans = true;
	}
	cout << (ans ? "YES\n"s : "NO\n"s);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
