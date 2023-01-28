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
	ans = 0;
	string s;
	for (i = 0; i < n; i++) {
		cin >> s;
		if (s == "For") {
			ans++;
		}else{
			ans--;
		}
	}
	if (ans > 0) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}