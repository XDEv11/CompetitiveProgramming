#include <iostream>
#include <array>

using namespace std;

void solve() {
	int n, q;
	cin >> n >> q;
	array<int, 51> f{};
	for (int i{1}; i <= n; ++i) {
		int c;
		cin >> c;
		if (!f[c]) f[c] = i;
	}

	while (q--) {
		int c;
		cin >> c;
		cout << f[c] << ' ';
		for (auto& p : f) if (p < f[c]) ++p;
		f[c] = 1;
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();

	return 0;
}
