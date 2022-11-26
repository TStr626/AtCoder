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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod, inf = 100000000;
	cin >> n >> m;
	vector<long long> a(m), p(n), q(n), pinv(n), qinv(n);
	rep(i, m) {
		cin >> a[i];
		a[i]--;
	}
	rep(j, n) {
		p[j] = j;
		pinv[j] = j;
	}
	for (i = m - 1; i >= 0; i--) {
		swap(p[a[i]], p[a[i] + 1]);
	}
	/*
	rep(j, n) {
		cout << p[j];
	}
	*/
	rep(j, n) {
		q[j] = j;
		qinv[j] = j;
	}
	rep(i, m) {
		swap(p[a[i]], p[a[i] + 1]);
		/*
		rep(j, n) {
			cout << qinv[q[pinv[j]]];
		}
		cout << endl;
		*/
		/*
		rep(j, n) {
			cout << p[qinv[j]];
		}
		cout << endl;
		*/
		ans = p[qinv[0]];
		cout << ans + 1 << endl;
		swap(q[a[i]], q[a[i] + 1]);
		qinv[q[a[i]]] = a[i];
		qinv[q[a[i] + 1]] = a[i] + 1;
	}
}