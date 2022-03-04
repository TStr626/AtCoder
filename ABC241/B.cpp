#include<iostream>
#include<vector>
#include<cmath>
#include<numeric>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<iomanip>
using namespace std;

# define rep(i,n) for(i=0; i<n; i++)


int main() {
	long long n, m, i, j, k, ans, cur, res, jud, mod = 998244353;
	cin >> n >> m;
	vector<long long> a(n), b(m);
	rep(i, n) {
		cin >> a[i];
	}
	rep(j, m) {
		cin >> b[j];
	}

	rep(j, m) {
		rep(i, n) {
			if (b[j] == a[i]) {
				a[i] = 0;
				break;
			}
		}
		if (i == n) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}