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
	long long a, b, c, d;
	cin >> a >> b >> c >> d;
	vector<string> s = { "Takahashi","Aoki" };
	if (a != c) {
		jud = (a > c);
	}
	else {
		jud = (b > d);
	}
	cout << s[jud] << endl;
}