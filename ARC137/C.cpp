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
	vector<long long> a(n), s(n);
	rep(i, n) {
		cin >> a[i];
	}
	
	
	if (a[n - 2] + 1 == a[n - 1] && ((a[n - 1] - (n - 1)) % 2 == 0)) {
		cout << "Bob" << endl;
	}
	else {
		cout << "Alice" << endl;
	}
}