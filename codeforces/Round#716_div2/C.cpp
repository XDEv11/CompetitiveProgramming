#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
	long long n;
	cin >> n;

	vector<bool> ans(n, false);
	ans[1] = true;

	vector<long long> v{};
	long long x{1};
	for (long long i{2}; i <= n - 1; ++i)
		if (gcd(i, n) == 1) {
			x = x * i % n;
			ans[i] = true;
		}
	if (x != 1) ans[x] = false;

	cout << count(ans.begin(), ans.end(), true) << '\n';
	for (long long i{0}; i < n; ++i)
		if (ans[i]) cout << i << ' ';
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
