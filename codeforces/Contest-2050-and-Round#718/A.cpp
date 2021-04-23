#include <iostream>

using namespace std;

void solve() {
	long long n;
	cin >> n;

	if (n % 2050) return cout << "-1\n", []{}();

	n /= 2050;
	int ans{0};
	while (n) {
		ans += n % 10;
		n /= 10;
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
