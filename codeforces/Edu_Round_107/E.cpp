#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static constexpr long long mod{998244353};
static long long power(long long x, long long y) { 
	long long ret{1};
	while (y > 0) {
		if (y & 1) ret = ret * x % mod; 
		y >>= 1; 
		x = x * x % mod;
	}
	return ret; 
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> b(n, vector<char>(m));
	for (auto& vt : b)
		for (auto& x : vt) cin >> x;

	int w{0};
	for (auto& vt : b)
		for (auto& x : vt) if (x == 'o') ++w;

	long long half{power(2, mod - 2)}, all{power(2, w)};
	vector<long long> e(max(n, m)); // expected value
	e[0] = 0;
	/* prob. of 1 / 2 that i     is the the same color */
	/* prob. of 1 / 2 that i + 1 is the the same color */
	for (int i{1}; i < e.size(); ++i)
		e[i] = (all * half % mod - e[i - 1]) * half % mod;

	long long ans{0};
	for (int i{0}; i < n; ++i) {
		int c{0};
		for (int j{0}; j + 1 < m; ++j) {
			if (b[i][j] == 'o' && b[i][j + 1] == 'o') {
				++c;
				ans += e[c];
			} else c = 0;
		}
	}
	for (int j{0}; j < m; ++j) {
		int c{0};
		for (int i{0}; i + 1 < n; ++i) {
			if (b[i][j] == 'o' && b[i + 1][j] == 'o') {
				++c;
				ans += e[c];
			} else c = 0;
		}
	}

	cout << (ans + mod) % mod << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();

	return 0;
}
