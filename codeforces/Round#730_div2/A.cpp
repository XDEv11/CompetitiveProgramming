#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void solve() {
	long long a, b;
	cin >> a >> b;
	if (a < b) swap(a, b);

	if (a == b) return cout << "0 0\n"s, []{}();

	long long d{a - b};
	cout << d << ' ' << min(a % d, d - a % d) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
