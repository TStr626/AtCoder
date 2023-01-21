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
	long long p, q, r, s;
	cin >> p >> q >> r >> s;
	vector<long long> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	
	for (i = 0; i <= q - p; i++) {
		swap(a[p - 1 + i], a[r - 1 + i]);
	}
	rep(i, n) {
		if (i) cout << ' ';
		cout << a[i];
	}
	cout << endl;
}