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
	cin >> n >> m;
	vector<string> s(n);
	rep(i, n) {
		cin >> s[i];
	}
	ans = 0; cur = 0;
	rep(j, m) {
		jud = 1;
		rep(i, n) {
			if (s[i][j] == 'x') {
				jud = 0;
			}
		}
		if (jud) {
			cur++;
			ans = max(ans, cur);
		}
		else {
			cur = 0;
		}
	}
	cout << ans << endl;
}