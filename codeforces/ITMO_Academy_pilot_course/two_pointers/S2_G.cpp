#include <iostream>
#include <vector>
#include <stack>
#include <functional>
#include <optional>
#include <numeric> // std::gcd()

using namespace std;

template<typename T>
class twoStack {
	function<T(const T&, const T&)> func;
	stack<pair<T, T>> s1{}, s2{};
	pair<T, T> rec{};
public:
	void push(T x) {
		if (s2.empty()) s2.emplace(x, x);
		else s2.emplace(x, func(x, s2.top().second));
	}
	void pop() {
		if (s1.empty() && s2.empty()) return ;
		if (s1.empty()) {
			s1.emplace(s2.top().first, s2.top().first), s2.pop();
			while (!s2.empty())
				s1.emplace(s2.top().first, func(s2.top().first, s1.top().second)), s2.pop();
		}
		rec = s1.top(); // record
		s1.pop();
	}
	void restore() { // call at most once after each pop()
		s1.push(rec);
	}
	optional<T> get() {
		if (s1.empty() && s2.empty()) return nullopt;
		if (s1.empty()) return s2.top().second;
		else if (s2.empty()) return s1.top().second;
		else return func(s1.top().second, s2.top().second);
	}
	twoStack(decltype(func)&& f) : func{f} {}
	twoStack(const decltype(func)& f) : func{f} {}
};

void solve() {
	int n;
	cin >> n;
	vector<long long> v(n);
	for (auto& x : v) cin >> x;

	twoStack<long long> GCD{gcd<long long, long long>};

	int ans{n + 1};
	int i{0};
	for (int j{0}; j < n; ++j) {
		GCD.push(v[j]);
		if (GCD.get() != 1) continue;

		while (GCD.get().value_or(-1) == 1) GCD.pop(), ++i;
		GCD.restore(), --i;
		ans = min(ans, j - i + 1);
	}
	
	cout << (ans == n + 1 ? -1 : ans) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
