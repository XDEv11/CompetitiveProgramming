#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> vx{}, vy{};
	for (int i{0}; i < 2 * n; ++i) {
		int x, y;
		cin >> x >> y;
		if (x) vx.push_back(abs(x));
		else vy.push_back(abs(y));
	}
	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());

	auto pow2 = [](int x) {return static_cast<long long>(x) * x;};

	double ans{0};
	for (int i{0}; i < n; ++i)
		ans += sqrt(static_cast<double>(pow2(vx[i]) + pow2(vy[i])));

	cout << fixed << setprecision(15) << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
