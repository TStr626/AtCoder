#include<iostream>
#include<vector>
#include<cmath>
#include<numeric>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<iomanip>
using namespace std;

# define rep(i,n) for(i=0; i<n; i++)
void yes() {
	cout << "Yes" << endl;
}
void no() {
	cout << "No" << endl;
}
void vec_h(vector<long long> a) {
	int n = a.size(), i;
	rep(i, n) {
		if (i) cout << ' ';
		cout << a[i];
	}
	cout << endl;
}
void vec_v(vector<long long> a) {
	for (auto c : a) {
		cout << c << endl;
	}
}

long long gcd(long long a, long long b) {
	if (b == 0) {
		return a;
	}
	if (a % b == 0) {
		return b;
	}
	return gcd(b, a % b);
}

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> n >> m;
	vector<vector<long long>> g(n);
	vector<long long> d(n, 0);
	rep(i, m) {
		cin >> x >> y;
		x--; y--;
		g[x].push_back(y);
		g[y].push_back(x);
		d[x]++; d[y]++;
	}
	if (n != m) {
		no();
		return 0;
	}
	vector<bool> checked(n, false);
	queue<long long> qu;
	rep(i, n) {
		if (checked[i]) {
			continue;
		}
		ans = 0; res = 0;
		qu.push(i);
		checked[i] = true;
		while (qu.size()) {
			cur = qu.front();
			qu.pop();
			ans++;
			res += d[cur];
			for (auto v : g[cur]) {
				if (checked[v]) {
					continue;
				}
				qu.push(v);
				checked[v] = true;
			}
		}
		if (ans * 2 != res) {
			no();
			return 0;
		}
	}
	yes();
}