#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <map>

using namespace std;

// Fermat Little Theorem
#define max_n 100000
constexpr long long P{1000000007};

vector<long long> fac(max_n + 1);
vector<long long> Invfac(max_n + 1);
/* Iterative Function to calculate (x^y) % P in O(log y) */
long long power(long long x, long long y) { 
	long long ret{1};
	while (y > 0) {
		if (y & 1) ret = (ret * x) % P; 
		y >>= 1; 
		x = (x * x) % P;
	}
	return ret; 
}
void buildTable() { 
	fac[0] = 1;
	Invfac[0] = power(1, P - 2);
	for (int i{1}; i < fac.size(); ++i) {
		fac[i] = (fac[i - 1] * i) % P;
		Invfac[i] = power(fac[i], P - 2);
	}
}
// Returns nCr % p using Fermat's little theorem.
long long nCr(int n, int r) {
	return fac[n] * Invfac[r] % P * Invfac[n - r] % P;
}

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	auto s{accumulate(v.begin(), v.end(), 0ll)};
	if (s % n) return cout << "0\n"s, []{}();

	auto m{s / n};
	int src{0}, snk{0};
	map<int, int> mp{};
	for (auto& x : v) {
		if (x == m) continue;
		x > m ? ++src : ++snk;
		++mp[x];
	}

	long long ans;
	if (src <= 1 || snk <= 1) ans = fac[src + snk];
	else ans = 2 * fac[src] * fac[snk] % P;
	for (auto& [x, c] : mp) ans = ans * Invfac[c] % P;
	ans = ans * nCr(n, src + snk) % P;

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	buildTable();

	int t{1};
	//cin >> t;
	while (t--) solve();

	return 0;
}
