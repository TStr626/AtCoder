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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353, inf = 1000000000;
	cin >> n >> x >> y;
	h = x + y;
	vector<long long> a(n), b(n), c(4, 0);
	jud = 0;
	rep(i, n) {
		cin >> a[i];
		b[i] = a[i] % h;
		jud = 0;
		if (b[i] >= x) {
			jud += 1;
		}
		if (b[i] >= y) {
			jud += 2;
		}
		c[jud]++;
	}
	if (c[1] + (c[3] > 0) > c[2]) {
		cout << "First" << endl;
	}
	else {
		cout << "Second" << endl;
	}

	
}