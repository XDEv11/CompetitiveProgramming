#include <iostream>
#include <queue>
#include <tuple>
#include <iomanip>

using namespace std;

void solve() {
	static constexpr double eps{1e-11}; // 10^-4 * 2^-20 > 10^-11

	double C, M, P, v;
	cin >> C >> M >> P >> v;

	queue<tuple<double, double, double, double>> qu{};
	qu.emplace(1., C, M, P);

	double ans{0.};
	while (!qu.empty()) {
		auto [pb, c, m, p]{qu.front()};
		qu.pop();

		ans += pb;
		if (c > eps && m > eps) {

			if (c - v <= eps) qu.emplace(pb * c, 0., m + c / 2, p + c / 2);
			else qu.emplace(pb * c, c - v, m + v / 2, p + v / 2);

			if (m - v <= eps) qu.emplace(pb * m, c + m / 2, 0., p + m / 2);
			else qu.emplace(pb * m, c + v / 2, m - v, p + v / 2);

		} else if (c > eps) {

			if (c - v <= eps) qu.emplace(pb * c, 0., 0., p + c);
			else qu.emplace(pb * c, c - v, 0., p + v);

		} else if (m > eps) {

			if (m - v <= eps) qu.emplace(pb * m, 0., 0., p + m);
			else qu.emplace(pb * m, 0., m - v, p + v);

		}
	}

	cout << fixed << setprecision(12) << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
