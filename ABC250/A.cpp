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
	long long n, m, i, j, k, h, w, ans, cur, res, jud, mod;
	long long r, c;
	cin >> h >> w >> r >> c;
	ans = 4;
	ans -= (r == h) + (r == 1) + (c == w) + (c == 1);
	cout << ans << endl;

}