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
	cin >> n;
	vector<string> vs(2*n);
	vector<bool> b(2 * n, true);
	rep(i, n) {
		cin >> vs[2 * i] >> vs[2 * i + 1];
	}
	
	rep(i, 2*n) {
		rep(j, 2 * n) {
			if (i / 2 == j / 2) continue;
			if (vs[i] == vs[j]) {
				b[i] = false;
				b[j] = false;
			}
		}
	}
	jud = 1;
	rep(i, n) {
		if ((b[2 * i] || b[2 * i + 1]) == false) {
			jud = 0;
		}
	}
	if(jud) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

}