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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod, inf;
	cin >> n;
	vector<long long> p(n);
	rep(i, n) {
		cin >> p[i];
	}
	vector<long long> f0(n + 1, 0), f1(3 * n + 1, 0);
	rep(i, n) {
		cur = (p[i] - i + n) % n;
		f0[0] += min(cur, n - cur);
		
		f1[cur] += 1;
		f1[n / 2 + cur] -= 1;
		f1[(n + 1) / 2 + cur] -= 1;
		f1[n + cur] += 1;
		f1[n+cur] += 1;
		f1[n+n / 2+cur] -= 1;
		f1[n+(n+1) / 2+cur] -= 1;
		f1[2*n+cur] += 1;
		f1[2*n+cur] += 1;
		
	}
	rep(i, 3 * n - 1) {
		f1[i + 1] += f1[i];
	}

	rep(i, n) {
		f0[i + 1] = f0[i] + f1[n + i];
	}
	/*
	rep(i, n) {
		cout << f1[i + n] << ' ';
	}
	cout << endl;
	rep(i, n) {
		cout << f0[i] << ' ';
	}
	*/
	ans = n * n;
	rep(i, n) {
		ans = min(ans, f0[i]);
	}
	cout << ans << endl;
	
}