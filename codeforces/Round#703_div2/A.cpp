#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<long long> v(n);
	for (auto& x : v) cin >> x;

	long long cnt{0};
	for (long long i{0}; i < n; ++i) {
		cnt += v[i] - i;
		if (cnt < 0) {
			cout << "NO\n";
			return ;
		}
	}
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
