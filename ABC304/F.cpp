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

long long powmod(long long n, long long m, long long mod) {
	// mod>0
	long long i, ans, cur, res;
	if (n % mod == 0) {
		return 0;
	}
	ans = 1; cur = n % mod; res = m;
	while (res > 0) {
		if (res % 2 == 1) {
			ans = (ans * cur) % mod;
		}
		cur = (cur * cur) % mod;
		res /= 2;
	}
	return ans;
}

vector<long long> divisorvector(long long n) {
	// returns divisor of n in O(sqrt(n))
	// need <algorithm>
	long long i;
	vector<long long> p;
	for (i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			p.push_back(i);
			if (i * i < n) {
				p.push_back(n / i);
			}
		}
	}
	sort(p.begin(), p.end());
	return p;
}

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> n;
	string s;
	cin >> s;
	vector<long long> p = divisorvector(n);
	// erase n-self
	p.pop_back();
	
	set<long long> st;
	map<long long, long long> mp;
	ans = 0;
	for (auto m : p) {
		st.clear();
		rep(i, n) {
			if (s[i] == '.') {
				st.insert(i % m);
			}
		}
		mp[m] += powmod(2, m - st.size(), mod);
		ans = (ans + mp[m] + mod) % mod;
		for (j = 2; j * m <= n; j++) {
			mp[j * m] = (mp[j * m] - mp[m] + mod) % mod;
		}
	}
	cout << ans << endl;
}