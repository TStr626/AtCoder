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
	vector<long long> a(5);
	rep(i, 5) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	if (a[0] == a[1] && a[1] == a[2] && a[2] != a[3] && a[3] == a[4]) {
		cout << "Yes" << endl;
	}
	else if (a[0] == a[1] && a[1] != a[2] && a[2] == a[3] && a[3] == a[4]) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}