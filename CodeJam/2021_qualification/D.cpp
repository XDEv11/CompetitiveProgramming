#include <iostream>
#include <vector>
#include <map>
#include <tuple>

using namespace std;

void solve(int n) {
	map<tuple<int, int, int>, int> mp{};
	auto ask = [&](int i, int j, int k) {
		if (i > j) swap(i, j);
		if (j > k) swap(j, k);
		if (i > j) swap(i, j);
	
		auto it{mp.find({i, j, k})};
		if (it != mp.end()) return it -> second;

		int l;
		cout << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
		cin >> l, --l;
		mp.emplace(make_tuple(i, j, k), l);
		return l;
	};
	auto ans = [](const vector<int>& a) {
		for (auto& x : a) cout << x + 1 << ' ';
		cout << endl;
		int res;
		return cin >> res, res;
	};


	vector<int> v{};
	v.insert(v.begin(), ask(0, 1, 2));
	{
		int i{0}, j{1};
		if (v[0] == 0) i = 1, j = 2;
		else if (v[0] == 1) j = 2;

		v.insert(v.begin(), i);
		v.insert(v.end(), j);
	}
	for (int i{3}; i < n; ++i) {
		int vs{v.size()};

		int l{0}, r{vs - 1};
		while (r - l >= 3) { // ternary search
			int m1{l + (r - l) / 3}, m2{r - (r - l) / 3};
			int ret{ask(i, v[m1], v[m2])};
			if (ret == i) l = m1, r = m2;
			else if (ret == v[m1]) r = m1;
			else if (ret == v[m2]) l = m2;
		}
		while (r - l > 1) { // binary search
			int m{(l + r) / 2};
			int ret{ask(i, v[m], v[m + 1])};
			if (ret == i) l = m, r = m + 1;
			else if (ret == v[m]) r = m;
			else l = m;
		}

		if (l == 0 && ask(i, v[0], v[1]) == v[0]) v.insert(v.begin(), i);
		else if (r == vs - 1 && ask(v[vs - 2], v[vs - 1], i) == v[vs - 1]) v.insert(v.end(), i);
		else v.insert(v.begin() + r, i);
	}

	ans(v);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t, n, q;
	cin >> t >> n >> q;
	while (t--) solve(n);

	return 0;
}
