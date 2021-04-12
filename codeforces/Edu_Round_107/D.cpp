#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;

	vector<int> v(k); iota(v.begin(), v.end(), 0);
	int x{0};
	while (n--) {
		cout << char('a' + x);
		auto t = v[x];
		if (x) v[x] = (v[x] - 1 + k) % k;
		else v[0] = (v[0] + 1) % k;
		x = t;
	}
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
