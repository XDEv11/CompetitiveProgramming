#include <iostream>
#include <vector>
#include <optional>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

// Extended Eculidean Algorithm
// solve Linear Diophantine Equation
template <typename T>
pair<T, T> operator- (const pair<T, T>& x, const pair<T, T>& y) {
    return {x.first - y.first, x.second - y.second};
}
template <typename T>
pair<T, T> operator* (const T& k, const pair<T, T>& p) {
    return {k * p.first, k * p.second};
}
template <typename T>
pair<T, T> extEuc(T X, T Y) {
    auto x{X}, y{Y};
    pair<T, T> p{1, 0}, q{0, 1};
    if (x < y) swap(x, y), swap(p, q); // let x >= y
    while (y) {
        auto n{p - (x / y) * q};
        auto r{x % y};    
        x = y, p = q;
        y = r, q = n;
    }
    return p;
}

void solve() {
	long long n, m, k;
	cin >> n >> m >> k, --k;
	long long nm{max(n, m)};
	vector<optional<long long>> a(2 * nm), b(2 * nm);
	for (int i{0}; i < n; ++i) {
		long long x;
		cin >> x, --x;
		a[x] = i;
	}
	for (int i{0}; i < m; ++i) {
		long long x;
		cin >> x, --x;
		b[x] = i;
	}

	priority_queue<long long, vector<long long>, greater<long long>> pq{};
	auto [_x, _y]{extEuc<long long>(n, m)};
	long long G{n * _x + m * _y}; // gcd
	for (int i{0}; i < 2 * nm; ++i) {
		if (!a[i] || !b[i]) continue;
		// a[i] + n * x = b[i] + m * y'
		// n * x + m * y = b[i] - a[i] = d
		auto x{_x}, y{_y};
		long long d{b[i].value() - a[i].value()};

		if (d % G) continue; // no solution

		x *= (d / G), y *= (d / G);
		if (x >= 0) {
			long long t{(x / (m / G))};
			x -= t * (m / G), y += t * (n / G);
		} else {
			long long t{((x - (m / G) + 1) / (m / G))};
			x += t * (m / G), y -= t * (n / G);
		}

		if (y > 0) {
			long long t{((y + (n / G) - 1) / (n / G))};
			x += t * (m / G), y -= t * (n / G);
		}

		pq.push(a[i].value() + n * x);
	}

	long long L{n * m / G}; // lcm
	long long r{k / (L - pq.size())};
	k %= (L - pq.size());
	long long d{0};
	while (true) {
		if (pq.empty() || pq.top() - 1 - d >= k) {
			d += k;
			break;
		}
		k -= pq.top() - 1 - d;
		d = pq.top();
		pq.pop();
	}

	cout << L * r + d + 1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
