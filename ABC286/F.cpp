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

#include<atcoder/math>
using namespace atcoder;
# define rep(i,n) for(i=0; i<n; i++)

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	// create a
	vector<long long> siz = { 4,9,5,7,11,13,17,19,23 };
	m = 108;

	vector<long long> a(m);
	j = 0; cur = 0;
	rep(i, siz.size()) {
		k = 0;
		while (k < siz[i]) {
			a[j] = cur + (k + 1) % siz[i];
			j++;
			k++;
		}
		cur += siz[i];
	}

	cout << m << endl;
	rep(i, m) {
		if (i)cout << ' ';
		cout << a[i] + 1;
	}
	cout << endl;

	// solve
	vector<long long> b(m);
	rep(i, m) {
		cin >> b[i];
		b[i]--;
	}
	vector<long long> r(siz.size());
	cur = 0;
	rep(i, siz.size()) {
		r[i] = b[cur] - cur;
		cur += siz[i];
	}
	pair<long long, long long> p = crt(r, siz);
	cout << p.first << endl;

}