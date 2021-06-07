#include <iostream>
#include <vector>
#include <numeric>
#include <map>
#include <utility>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	map<pair<int, int>, int> mp{};
	int cntD{0}, cntK{0};
	for (int i{0}; i < n; ++i) {
		cntD += (v[i] == 'D');
		cntK += (v[i] == 'K');

		int g{gcd(cntD, cntK)};
		pair<int, int> ratio{cntD / g, cntK / g};

		auto it{mp.find(ratio)};
		if (it != mp.end()) cout << ++it->second;
		else mp.emplace(ratio, 1), cout << 1;
		cout << " \n"[i == n - 1];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
