#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

constexpr long long MAX{20000000};
vector<int> md(MAX + 1, 0); // min divisor
vector<int> pd(MAX + 1, 0); // number of prime divisors
void build() {
	for (long long i{2}; i <= MAX; ++i) {
		if (md[i]) continue;
		md[i] = i;
		for (long long j{i * i}; j <= MAX; j += i)
			if (!md[j]) md[j] = i;
	}
	for (int i{2}; i <= MAX; ++i) {
		int j{i / md[i]};
		pd[i] = pd[j] + (md[i] != md[j]);
	}
}

void solve() {
	// c * lcm(a, b) - d * gcd(a, b) = x
	int c, d, x;
	cin >> c >> d >> x;

	long long ans{0};
	for (int g{1}; g * g <= x; ++g) {
		if (x % g) continue;
		int k{x / g + d};
		if (k % c == 0) ans += 1 << pd[k / c];

		if (x / g != g) {
			k = g + d;
			if (k % c == 0) ans += 1 << pd[k / c];
		}
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	build();

	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
