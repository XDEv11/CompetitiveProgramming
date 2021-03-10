#include <iostream>
#include <vector>
#include <stack>
#include <functional>
#include <optional>
#include <algorithm> // std::max, std::min

using namespace std;

template<typename T>
class twoStack {
	function<T(const T&, const T&)> func;
	stack<pair<T, T>> s1{}, s2{};
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
		s1.pop();
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
	long long k;
	cin >> n >> k;
	vector<long long> v(n);
	for (auto& x : v) cin >> x;

	twoStack<long long> MX{[](const long long& x, const long long& y){return max(x, y);}};
	twoStack<long long> MN{[](const long long& x, const long long& y){return min(x, y);}};

	long long ans{0};
	int i{0};
	for (int j{0}; j < n; ++j) {
		MX.push(v[j]), MN.push(v[j]);
		while (MX.get().value() - MN.get().value() > k) MX.pop(), MN.pop(), ++i;
		ans += (j - i + 1);
	}
	
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
