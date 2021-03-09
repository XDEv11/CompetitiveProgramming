#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

constexpr long long MAX{200000};

vector<int> sp(MAX + 1, 0); // smallest prime
void build() {
	for (long long i{2}; i <= MAX; ++i) {
		if (sp[i]) continue;
		sp[i] = i;
		for (long long j{i * i}; j <= MAX; j += i)
			if (!sp[j]) sp[j] = i;
	}
}

void solve() {
	int n, q;
	cin >> n >> q;

	auto mod_{[](long long& x) {x %= 1000000007;}};

	long long ans{1};
	vector<map<int, int>> mp(n);
	vector<multiset<int>> ms(MAX + 1);
	auto mul{
		[&](int i, int x) {
			while (x != 1) {
				int p{sp[x]}, cnt{0};
				while (sp[x] == p) x /= p, ++cnt;

				int lst_mn{0};
				if (ms[p].size() == n) lst_mn = *ms[p].begin();

				if (mp[i][p]) ms[p].erase(ms[p].find(mp[i][p]));
				mp[i][p] += cnt;
				ms[p].insert(mp[i][p]);

				if (ms[p].size() == n) {
					int mn{*ms[p].begin()};
					for (int k{0}; k < mn - lst_mn; ++k) mod_(ans *= p);
				}
			}
		}
	};

	for (int i{0}; i < n; ++i) {
		int x;
		cin >> x;
		mul(i, x);
	}

	while (q--) {
		int i, x;
		cin >> i >> x, --i;
		mul(i, x);
		cout << ans << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	build();

	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
