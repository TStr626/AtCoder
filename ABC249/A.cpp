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
	long long a, b, c, d, e, f, ans1, ans2;
	cin >> a >> b >> c >> d >> e >> f >> k;
	ans1 = a * (k / (a + c)) + min(a, k % (a + c));
	ans1 *= a;
	ans2 = d * (k / (d + f)) +  min(d, k % (d + f));
	ans2 *= e;
	if (ans1 > ans2) {
		cout << "Takahashi" << endl;
	}
	else if (ans2 > ans1) {
		cout << "Aoki" << endl;
	}
	else {
		cout << "Draw" << endl;
	}

}