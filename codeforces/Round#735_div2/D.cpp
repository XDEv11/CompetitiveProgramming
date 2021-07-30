#include <iostream>

using namespace std;

void solve() {
	int n;
	cin >> n;

	if (n == 1) return cout << "a\n"s, []{}();

	for (int i{0}; i < n / 2; ++i) cout << 'a';
	cout << (n & 1 ? "bc"s : "b"s);
	for (int i{0}; i < n / 2 - 1; ++i) cout << 'a';
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
