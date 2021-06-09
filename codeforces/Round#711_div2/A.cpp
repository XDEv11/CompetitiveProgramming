#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

static long long gcdsum(long long x) {
	long long y{0}, t{x};
	while (t) y += t % 10, t /= 10;
	return gcd(x, y);
}

void solve() {
	long long n;
	cin >> n;

	while (gcdsum(n) == 1) ++n;
	cout << n << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
