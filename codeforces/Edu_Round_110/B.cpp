#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	long long ce{0};
	for (auto& x : v)
		if ((x & 1) == 0) ++ce;
	long long ans{ce * ((n - 1) + (n - ce)) / 2};

	vector<int> v2{};
	for (auto& x : v)
		if ((x & 1) == 1) v2.push_back(x);
	v = move(v2);

	for (int i{0}; i < v.size(); ++i)
		for (int j{i + 1}; j < v.size(); ++j)
			if (gcd(v[i], v[j]) != 1) ++ans;

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
