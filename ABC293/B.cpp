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

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n;
	vector<long long> a(n, 0), b(n, 0);
	ans = n;
	rep(i, n) {
		cin >> a[i];
		a[i]--;
		if (!b[i]) {
			if (b[a[i]] == 0) {
				ans--;
			}
			b[a[i]]++;
		}
	}
	cout << ans << endl;
	cur = 0;
	rep(i, n) {
		if (!b[i]) {
			if (cur) cout << ' ';
			cout << i + 1;
			cur++;
		}
	}
	cout << endl;
}