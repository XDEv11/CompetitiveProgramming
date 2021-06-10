#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

static inline bool ask(int u, int v) {
	cout << "? "s << u + 1 << ' ' << v + 1 << endl;
	string ret;
	return cin >> ret, ret == "Yes"s;
}

static inline void answer(int a, int b) {
	cout << "! "s << a + 1 << ' ' << b + 1 << endl;
}

void solve() {
	int n;
	cin >> n;
	vector<int> k(n);
	for (auto& x : k) cin >> x;
	
	vector<pair<int, pair<int, int>>> v{};
	for (int i{0}; i < n; ++i)
		for (int j{i + 1}; j < n; ++j) {
			if (k[i] <= k[j]) v.emplace_back(k[j] - k[i], make_pair(i, j));
			else v.emplace_back(k[i] - k[j], make_pair(j, i));
		}
	sort(v.rbegin(), v.rend());

	for (auto& [_, p] : v) {
		auto& [a, b]{p};
		if (ask(b, a)) return answer(b, a);
	}
	answer(-1, -1);
}

/* https://codeforces.com/blog/entry/89137?#comment-775682 (dengyaotriangle) */

#define fi first
#define se second

void solve2() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i{0}; i < n; ++i) {
		cin >> v[i].fi;
		v[i].se = i;
	}
	sort(v.begin(), v.end());

	int sum{0}, fst{0};
	pair<int, pair<int, int>> ans{-1, {-1, -1}};
	for (int i{0}; i < n; ++i) {
		sum += v[i].fi;
		if (sum == (i + 1) * i / 2) { // last node of a SCC
			if (fst != i && v[i].fi - v[fst].fi > ans.fi) // more than one node in this SCC
				ans = {v[i].fi - v[fst].fi, {v[fst].se, v[i].se}};

			fst = i + 1; // first node of next SCC
		}
	}
	answer(ans.se.fi, ans.se.se);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve2();

	return 0;
}
