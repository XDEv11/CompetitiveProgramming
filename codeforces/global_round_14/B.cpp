#include <iostream>

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

static inline bool is_perfect_square(unsigned long long x) {
	auto t{Intsqrt(x)};
	return t * t == x;
}

void solve() {
	int n;
	cin >> n;

	cout << ((n % 2 == 0 && is_perfect_square(n / 2)) || (n % 4 == 0 && is_perfect_square(n / 4)) ?
			"YES\n"s : "NO\n"s);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
