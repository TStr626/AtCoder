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
	long long a, b, l;
	cin >> n >> a >> b;

	rep(i, a*n) {
		rep(j, b * n) {
			cur = i / a + j / b;
			if (cur % 2) {
				cout << '#';
			}
			else {
				cout << '.';
			}
		}
		cout << endl;
	}
}