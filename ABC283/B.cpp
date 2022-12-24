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

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n;
	vector<long long> a(n);
	rep(i, n) {
		cin >> a[i];
	}

	long long q, t;
	cin >> q;
	while (q--) {
		cin >> t;
		if (t == 1) {
			cin >> k >> x;
			a[k - 1] = x;
		}
		else {
			cin >> k;
			cout << a[k - 1] << endl;
		}
	}
}