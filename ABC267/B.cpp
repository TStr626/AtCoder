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
	long long n, m, i, j, k, h, w, ans, cur, res, jud, mod = 998244353;
	string s;
	vector<long long> lin = { 1,1,2,2,2,1,1 };
	vector<long long> pl = { 3,2,4,1,3,5,0,2,4,6 };
	cin >> s;
	rep(i, 10) {
		if (s[i] == '0') {
			lin[pl[i]]--;
		}
	}

	jud = 0;
	rep(i, 7) {
		for (j = i + 2; j < 7; j++) {
			if (lin[i] && lin[j]) {
				for (k = i + 1; k < j; k++) {
					if (lin[k] == 0) {
						jud = 1;
					}
				}
			}
		}
	}
	if (s[0] == '1') {
		jud = 0;
	}
	if (jud) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}