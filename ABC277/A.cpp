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
	cin >> n >> x;
	x--;
	vector<long long> p(n), pinv(n);
	rep(i, n) {
		cin >> p[i];
		p[i]--;
		pinv[p[i]] = i;
	}
	cout << pinv[x] + 1 << endl;
}