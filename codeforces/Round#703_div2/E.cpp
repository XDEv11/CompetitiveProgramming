#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <optional>
#include <algorithm>

using namespace std;

// Dijkstra algorithm
template <typename T>
class graph {
public:
    int n;
    vector<vector<pair<int, T>>> adj;
    vector<optional<T>> d;
    explicit graph(int _n) : n{_n}, adj(n), d(n) {}

    void dijkstra(int s) {
        vector<bool> found(n, false);
        fill(d.begin(), d.end(), nullopt);
        d[s] = 0;

        using pq_t = pair<T, int>;
        priority_queue<pq_t, vector<pq_t>, greater<pq_t>> pq{};
        pq.emplace(0, s);
        while (!pq.empty()) {
            auto [_, u]{pq.top()}; pq.pop();
            if (found[u]) continue;
            found[u] = true;
            for (auto& [v, w] : adj[u])
                if (!d[v] || d[v] > d[u].value() + w) {
                    d[v] = d[u].value() + w;
                    pq.emplace(d[v].value(), v);
                }
        }
    }
};

void solve() {
	int n, m;
	cin >> n >> m;

	constexpr int mxw{50}; // [1:mxw]
	graph<int> gph{n * (mxw + 1)};
	auto add_edge = [&](int u, int v, int w) {
		gph.adj[u * (mxw + 1)].emplace_back(v * (mxw + 1) + w, 0);
		for (int lastw{1}; lastw <= mxw; ++lastw)
			gph.adj[u * (mxw + 1) + lastw].emplace_back(v * (mxw + 1), (w + lastw) * (w + lastw));
	};
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w, --u, --v;

		add_edge(u, v, w);
		add_edge(v, u, w);
	}

	gph.dijkstra(0);

	for (int i{0}; i < n; ++i) cout << gph.d[i * (mxw + 1)].value_or(-1) << ' ';
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
