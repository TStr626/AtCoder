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
	cin >> n;
	string s;
	cin >> s;
	vector<long long> a(n);
	rep(i, n) {
		if (s[i] == 'd') {
			a[i] = 0;
		}
		else {
			a[i] = 1;
		}
	}

	
	i = 0;
	while (i < n && a[i] == 0) {
		i++;
	}
	vector<long long> b(n - i), c(n - i);
	res = i;
	for (k = 0; k < n - i; k++) {
		b[k] = a[i + k];
	}

	for (j = i; j < n; j++) {
		jud = 1;
		for (k = 0; k <= j - i; k++) {
			c[k] = 1 - a[j - k];
			if (jud == 1) {
				if (c[k] > b[k]) {
					jud = 0;
				}
				else if (c[k] < b[k]) {
					jud = 2;
				}
			}
		}

		if (jud == 2) {
			for (k = 0; k <= j - i; k++) {
				b[k] = c[k];
			}
		}
	}

	rep(j, n) {
		if (j < i) {
			cout << (a[j] == 0 ? 'd' : 'p');
		}
		else {
			cout << (b[j-i] == 0 ? 'd' : 'p');
		}

	}

}