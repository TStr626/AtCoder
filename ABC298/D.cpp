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


int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	long long query;
	cin >> query;
	queue<int> qu;
	ans = 1;
	qu.push(1);
	while (query--) {
		cin >> k;
		if (k == 1) {
			cin >> x;
			qu.push(x);
			ans = (ans * 10 + x) % mod;
		}
		else if (k == 2) {
			cur = qu.front();
			qu.pop();
			cur = (cur * powmod(10, qu.size(), mod)) % mod;
			ans = (ans - cur + mod) % mod;
		}
		else {
			cout << ans << endl;
		}
	}
	
}