#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void solve() {
	static int t{0};
	cout << "Case #" << ++t << ": ";

	int n, q;
	cin >> n >> q;
	vector<vector<bool>> ans(n, vector<bool>(q));
	vector<int> s(n);
	for (int i{0}; i < n; ++i) {
		for (int j{0}; j < q; ++j) {
			char c;
			cin >> c;
			ans[i][j] = (c == 'T');
		}
		cin >> s[i];
	}

	auto check = [&](unsigned long long mask) {
		for (int i{0}; i < n; ++i) {
			int rs{0};
			for (int j{0}; j < q; ++j) rs += ans[i][j] == (mask & (1ULL << j) ? true : false);
			if (rs != s[i]) return false;
		}
		return true;
	};

	vector<int> cnt(q);

	unsigned long long pos{0};
	for (unsigned long long mask{0}; mask < (1ULL << q); ++mask) {
		if (check(mask)) {
			for (int j{0}; j < q; ++j)
				if (mask & (1ULL << j)) ++cnt[j];
			++pos;
		}
	}

	unsigned long long score{0};
	for (int j{0}; j < q; ++j) {
		if (2 * cnt[j] >= pos) score += cnt[j], cout << 'T';
		else score += pos - cnt[j], cout << 'F';
	}
	auto g{gcd(score, pos)};
	cout << ' ' << (score / g) << '/' << (pos / g) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
