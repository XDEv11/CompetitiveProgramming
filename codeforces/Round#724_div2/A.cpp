#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	if (*min_element(v.begin(), v.end()) < 0) return cout << "NO\n"s, []{}();

	cout << "YES\n"s;
	cout << "101\n"s;
	for (int i{0}; i <= 100; ++i) cout << i << " \n"s[i == 100];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
