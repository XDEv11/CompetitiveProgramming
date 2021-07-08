#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<long long> v(n);
	for (auto& x : v) cin >> x;

	long long s{accumulate(v.begin(), v.end(), 0ll)}, r{s % n};
	
	cout << r * (n - r) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
