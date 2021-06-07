#include <iostream>
#include <cmath>

using namespace std;

void solve() {
	int n, k1, k2, w, b;
	cin >> n >> k1 >> k2 >> w >> b;

	int mxw{min(k1, k2) + abs(k1 - k2) / 2};
	k1 = n - k1, k2 = n - k2;
	int mxb{min(k1, k2) + abs(k1 - k2) / 2};

	if (w <= mxw && b <= mxb) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
