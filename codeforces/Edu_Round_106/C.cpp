#include <iostream>
#include <vector>

using namespace std;

void solve() {
	constexpr long long MAX{1000000000};

	int n;
	cin >> n;
	vector<long long> v(n);
	for (auto& x : v) cin >> x;

	long long ans{2 * n * MAX};
	{
		long long up{0}, rt{0}, mnup{MAX}, mnrt{MAX};
		for (int i{0}; i < n; ++i) {
			if (i & 1) rt += v[i], mnrt = min(mnrt, v[i]);
			else up += v[i], mnup = min(mnup, v[i]);
			ans = min(ans, up + rt + (n - (i + 2) / 2) * mnup + (n - (i + 1) / 2) * mnrt);
		}
	}
	{
		long long up{0}, rt{0}, mnup{MAX}, mnrt{MAX};
		for (int i{0}; i < n; ++i) {
			if (i & 1) up += v[i], mnup = min(mnup, v[i]);
			else rt += v[i], mnrt = min(mnrt, v[i]);
			ans = min(ans, up + rt + (n - (i + 1) / 2) * mnup + (n - (i + 2) / 2) * mnrt);
		}
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
