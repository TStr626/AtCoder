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

bool judge(long long h, long long m) {
	long long h2, m2;
	h2 = h - h%10 + m / 10;
	m2 = m % 10 + (h % 10) * 10;
	if (0 <= h2 && h2 <= 23 && 0 <= m2 && m2 <= 59) {
		return true;
	}
	return false;
}
int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> h >> m;

	while (true) {
		if (judge(h, m) == true) {
			cout << h << ' ' << m << endl;
			return 0;
		}
		m++;
		if (m == 60) {
			m = 0;
			h++;
		}
		if (h == 24) {
			h = 0;
		}
	}
}