#include <iostream>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;

	if (m < n) return cout << "0\n"s, []{}();

	int x{m + 1};
	bool flag{false};
	for (int i{29}; i >= 0; --i) {
		if ((x & (1 << i)) == (n & (1 << i))) continue;
		if (x & (1 << i)) {
			if (flag) x ^= (1 << i);
		} else {
			flag = true, x ^= (1 << i);
		}
	}

	cout << (n ^ x) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
