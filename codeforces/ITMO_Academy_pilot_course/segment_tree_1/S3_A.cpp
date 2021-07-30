#include <iostream>
#include <vector>
#include <functional>

using namespace std;

template<typename value_t, class merge_t>
class SGT {
    int n;
    vector<value_t> t; // root starts at 1
    merge_t merge; // associative function for SGT
public:
    explicit SGT(int _n = 0, const merge_t& _merge = merge_t{})
        : n{_n}, t(2 * n), merge{_merge} {}
    void build(const vector<value_t>& v) {
        n = v.size(), t.resize(2 * n);
        for (int p{2 * n - 1}; p >= n; --p) t[p] = v[p - n];
        for (int p{n - 1}; p >= 0; --p) t[p] = merge(t[p << 1], t[(p << 1) + 1]);
    }
    void modify(int p, const value_t& x) {
        for (t[p += n] = x; p > 1; p >>= 1) t[p >> 1] = merge(t[p], t[p ^ 1]);
    }
    value_t query(int l, int r, value_t init) { // [l:r)
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) init = merge(init, t[l++]);
            if (r & 1) init = merge(init, t[--r]);
        }
        return init;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v) cin >> x;

    SGT<int, plus<int>> sgt{};
    sgt.build(vector<int>(n + 1, 0));

    vector<int> inv(n);
    for (int i{0}; i < n; ++i) {
		inv[i] = sgt.query(v[i] + 1, n + 1, 0);
        sgt.modify(v[i], sgt.query(v[i], v[i] + 1, 0) + 1);
    }

    for (auto& x : inv) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t{1};
    // cin >> t;
    while (t--) solve();
    
    return 0;
}
