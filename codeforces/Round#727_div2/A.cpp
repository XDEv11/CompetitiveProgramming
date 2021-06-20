#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	long long n, x, t;
	cin >> n >> x >> t;

	long long ans{0}, k{t / x};

	ans += min(n, k) * (min(n, k) - 1) / 2;
	if (n > k) ans += (n - k) * k;

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
