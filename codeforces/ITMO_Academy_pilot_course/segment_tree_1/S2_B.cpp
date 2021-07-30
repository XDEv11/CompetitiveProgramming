#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class SGT {
    int n;
    vector<int> t;
    int left(int tv) { return tv + 1; }
    int right(int tv, int tl, int tm) { return tv + 2 * (tm - tl); }
    void build(const vector<int>& v, int tv, int tl, int tr) {
        if (tr - tl == 1) t[tv] = v[tl];
        else {
            int tm{(tl + tr) / 2};
            build(v, left(tv), tl, tm);
            build(v, right(tv, tl, tm), tm, tr);
            t[tv] = t[left(tv)] + t[right(tv, tl, tm)];
        }
    }
    void flip(int p, int tv, int tl, int tr) {
        if (tr - tl == 1) t[tv] = (t[tv] == 0 ? 1 : 0);
        else {
            int tm{(tl + tr) / 2};
            if (p < tm) flip(p, left(tv), tl, tm);
            else flip(p, right(tv, tl, tm), tm, tr);
            t[tv] = t[left(tv)] + t[right(tv, tl, tm)];
        }
    }
public:
    SGT(const vector<int>& v) : n{v.size()}, t(2 * n) {
        build(v, 1, 0, n);
    }
    void flip(int p) {
        flip(p, 1, 0, n);
    };
    int ps_lower_bound(int ps) { // prefix sum lower bound
        if (t[1] < ps) return n;
        int tv{1}, tl{0}, tr{n};
        while (tr - tl > 1) {
            int tm{(tl + tr) / 2};
            if (t[left(tv)] >= ps) tv = left(tv), tr = tm;
            else ps -= t[left(tv)], tv = right(tv, tl, tm), tl = tm;
        }
        return tl;
    }
};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	SGT sgt{v};

	while (m--) {
		int op, var;
		cin >> op >> var;
		if (op == 1) sgt.flip(var);
		else if (op == 2) cout << sgt.ps_lower_bound(var + 1) << '\n'; // k-th one (actually (k+1) one's)
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t{1};
	// cin >> t;
	while (t--) solve();
	
	return 0;
}
