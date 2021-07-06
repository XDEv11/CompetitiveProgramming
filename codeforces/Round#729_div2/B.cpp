#include <iostream>
#include <string>

using namespace std;

void solve() {
	long long n, a, b;
	cin >> n >> a >> b;

	long long x{1};
	while (x <= n) {
		if ((n - x) % b == 0) return cout << "Yes\n"s, []{}();
		if (a == 1) break;
		x *= a;
	}
	cout << "No\n"s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
