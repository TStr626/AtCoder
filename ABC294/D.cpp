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
	long long query, t;
	cin >> n >> query;
	set<long long> st;
	cur = 1;
	while (query--) {
		cin >> t;
		if (t == 1) {
			// first call
			st.insert(cur);
			cur++;
		}
		if (t == 2) {
			// come
			cin >> x;
			st.erase(x);
		}
		if (t == 3) {
			// query
			cout << *st.begin() << endl;
		}
	}
}