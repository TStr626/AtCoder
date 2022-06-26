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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod, inf=1100000000;
	vector<long long> a(3);
	cin >> a[0] >> a[1] >> a[2];
	sort(a.begin(), a.end());
	
	cur = a[2] - a[0] + a[2] - a[1];
	if (cur > a[2]) {
		ans = -1;
	}
	else {
		ans = a[2];
	}
	cout << ans << endl;


}