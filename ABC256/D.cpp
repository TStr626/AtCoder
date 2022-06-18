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
	h = 200000;
	vector<long long> s(h + 1);
	rep(i, n) {
		cin >> x >> y;
		s[x]++; s[y]--;
	}

	rep(i, h) {
		s[i + 1] += s[i];
	}

	for (i = 1; i <= h; i++) {
		if (!s[i - 1] && s[i]) {
			cout << i << ' ';
		}
		if (s[i - 1] && !s[i]) {
			cout << i << endl;
		}
	}
}