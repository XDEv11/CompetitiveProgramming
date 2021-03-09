#include <iostream>
#include <vector>
#include <set>

using namespace std;

void solve() {
	int n;
	long long k;
	cin >> n >> k;
	vector<long long> v(n);
	for (auto& x : v) cin >> x;

	multiset<long long> ms{};
	long long ans{0};
	int i{0};
	for (int j{0}; j < n; ++j) {
		ms.insert(v[j]);
		while (*prev(ms.end()) - *ms.begin() > k) ms.erase(ms.find(v[i++]));
		ans += (j - i + 1);
	}
	
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
