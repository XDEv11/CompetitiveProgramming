#include <iostream>

using namespace std;

static constexpr long long P{1000000007};
/* Iterative Function to calculate (x^y) % P in O(log y) */
static long long power(long long x, long long y) { 
	long long ret{1};
	while (y > 0) {
		if (y & 1) ret = (ret * x) % P; 
		y >>= 1; 
		x = (x * x) % P;
	}
	return ret; 
}

void solve() {
	long long n, k;
	cin >> n >> k;

	cout << power(n, k) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
