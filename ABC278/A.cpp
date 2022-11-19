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
	cin >> n >> k;
	vector<long long> a(n + k);
	rep(i, n) {
		cin >> a[i];
	}
	rep(j, k) {
		a[n + j] = 0;
	}
	rep(i, n) {
		if (i) cout << ' ';
		cout << a[k + i];
	}
	cout << endl;
}