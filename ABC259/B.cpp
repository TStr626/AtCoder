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
	double a, b, c, d, rad, l;
	cin >> a >> b >> d;
	l = sqrt(a * a + b * b);
	c = atan2(b, a);
	rad = c + d * acos(-1.0) / 180.0;
	//cout << d * acos(-1.0) / 180.0 << endl;
	cout << setprecision(10);
	cout << l * cos(rad) << ' ' << l * sin(rad) << endl;
}