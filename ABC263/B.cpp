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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n;
	vector<long long> p(n);
	p[0] = -1;
	rep(i, n - 1) {
		cin >> p[i + 1];
		p[i + 1]--;
	}
	cur = n - 1; ans = 0;
	while (cur != 0) {
		cur = p[cur];
		ans++;
	}
	cout << ans << endl;
}