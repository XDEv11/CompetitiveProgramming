#include <iostream>
#include <queue>
#include <utility>

using namespace std;

static int get() {
	int a;
	cin >> a;
	return a;
}

static void put(int b, pair<int, int> p) {
	auto& [i, j]{p};
	cout << b << ' ' << i + 1 << ' ' << j + 1 << endl;
}

void solve() {
	int n;
	cin >> n;

	queue<pair<int, int>> q1{}, q2{};
	for (int i{0}; i < n; ++i)
		for (int j{0}; j < n; ++j) {
			(i & 1) ^ (j & 1) ? q1.emplace(i, j) : q2.emplace(i, j);
		}

	int r{n * n};
	while (r--) {
		int c{get()};
		if (c == 1)
			q2.empty() ? (put(3, q1.front()), q1.pop()) : (put(2, q2.front()), q2.pop());
		else if (c == 2)
			q1.empty() ? (put(3, q2.front()), q2.pop()) : (put(1, q1.front()), q1.pop());
		else
			q1.empty() ? (put(2, q2.front()), q2.pop()) : (put(1, q1.front()), q1.pop());
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
