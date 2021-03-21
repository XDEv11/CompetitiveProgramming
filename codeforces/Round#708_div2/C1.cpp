#include <iostream>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;

	if (n & 1) { // odd
		cout << 1 << ' ' << (n / 2) << ' ' << (n / 2) << '\n';
	} else if ((n / 2) & 1) {
		n -= 2;
		cout << 2 << ' ' << (n / 2) << ' ' << (n / 2) << '\n';
	} else {
		cout << (n / 4) << ' ' << (n / 4) << ' ' << (n / 2) << '\n';
	}	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
