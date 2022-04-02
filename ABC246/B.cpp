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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> x >> y;
	double ansx, ansy,d;
	d = sqrt(x * x + y * y);
	ansx = double(x) / d;
	ansy = double(y) / d;
	cout << setprecision(9);
	cout << ansx << ' ' << ansy << endl;
}